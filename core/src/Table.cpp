#include "Table.h"

Table::Table(const std::map<unsigned int, std::string> &nameColumns,
             const std::map<unsigned int, int> &typeColumns,
             const std::map<unsigned int, std::string> &formulaColumns,
             const std::map<unsigned int, std::string> &colorColumns,
             const std::map<std::string, int> &colorPriority,
             const std::map<unsigned int, std::string> &unitColumns)
    : _unitColumns(unitColumns) {
    BOOST_FOREACH (auto &m_pair, nameColumns) {
        this->_nameColumns[m_pair.first] = m_pair.second;
        boost::algorithm::to_lower(this->_nameColumns[m_pair.first]);
    }

    BOOST_FOREACH (auto &m_pair, formulaColumns) {
        this->_formulaColumns[m_pair.first] = m_pair.second;
        boost::algorithm::to_lower(this->_formulaColumns[m_pair.first]);
    }
    BOOST_FOREACH (auto &m_pair, colorColumns) {
        this->_colorColumns[m_pair.first] = m_pair.second;
        boost::algorithm::to_lower(this->_colorColumns[m_pair.first]);
    }
    BOOST_FOREACH (auto &m_pair, colorPriority) {
        auto color = m_pair.first;
        boost::algorithm::to_lower(color);
        this->_colorPriority[color] = m_pair.second;
    }

    BOOST_FOREACH (auto &m_pair, typeColumns) {
        switch (m_pair.second) {
            case DvType::TYPE_NUMBER:
                this->_typeColumns[m_pair.first] = DvType::TYPE_NUMBER;
                this->_numberColumns.push_back(m_pair.first);
                break;
            case DvType::TYPE_STRING:
                this->_typeColumns[m_pair.first] = DvType::TYPE_STRING;
                break;
            case DvType::TYPE_BOOLEAN:
                this->_typeColumns[m_pair.first] = DvType::TYPE_BOOLEAN;
                break;
            case DvType::TYPE_TIME:
                this->_typeColumns[m_pair.first] = DvType::TYPE_TIME;
                break;
            case DvType::TYPE_DATE:
                this->_typeColumns[m_pair.first] = DvType::TYPE_DATE;
                break;
            case DvType::TYPE_DATETIME:
                this->_typeColumns[m_pair.first] = DvType::TYPE_DATETIME;
                break;
            default:
                this->_typeColumns[m_pair.first] = DvType::TYPE_OTHER;
        }
    }

    if (!Py_IsInitialized()) {
        BOOST_LOG_TRIVIAL(debug) << "Initilaze python interpritator";
        Py_Initialize();
    }
}

std::map<unsigned int, DynamicValue> Table::calculationRowValues(
    std::map<unsigned int, DynamicValue> rowValues) {
    this->recalculationRowValues(rowValues);
    return rowValues;
}

TreeNode Table::calculationTree(
    TreeNode node, std::map<unsigned int, std::string> aggregationColumns,
    unsigned int activeNode) {
    this->recalculationTree(node, aggregationColumns, activeNode);

    return node;
}

std::vector<unsigned int> Table::_getPriorityFormulas(
    const std::map<unsigned int, std::string> &formulaColumns) {
    std::set<unsigned int> allVisited;
    std::vector<unsigned int> priority;
    std::map<std::string, unsigned int> m_columnsByName =
        swapPairs<unsigned int, std::string>(this->_nameColumns);

    BOOST_FOREACH (auto &m_pair, formulaColumns) {
        if (allVisited.find(m_pair.first) == allVisited.end()) {
            auto res = this->_setPriority(priority, m_pair.first,
                                          formulaColumns, m_columnsByName);
            allVisited.insert(res.begin(), res.end());
        }
    }

    return priority;
}

std::set<unsigned int> Table::_setPriority(
    std::vector<unsigned int> &priority, unsigned int idColumn,
    const std::map<unsigned int, std::string> &formulas,
    const std::map<std::string, unsigned int> &m_columnsByName,
    std::set<unsigned int> visited) {
    std::set<unsigned int> allVisited;
    visited.insert(idColumn);

    antlr4::ANTLRInputStream input(formulas.at(idColumn));
    CalcValueLexer lexer(&input);
    auto tokens = lexer.getAllTokens();
    std::set<std::string> uniqueColumnNames;

    //! get unique column names
    BOOST_FOREACH (auto &token, tokens) {
        if (token->getType() == CalcValueLexer::COLUMN) {
            uniqueColumnNames.insert(token->getText());
        }
    }

    BOOST_FOREACH (auto &columnName, uniqueColumnNames) {
        if (m_columnsByName.find(columnName) == m_columnsByName.end()) {
            auto msg = "The formula %s contains a non-existing column %s";

            throw FormulaException(
                (boost::format(msg) % formulas.at(idColumn) % columnName)
                    .str());
        }

        if (formulas.find(m_columnsByName.at(columnName)) != formulas.end()) {
            if (visited.find(m_columnsByName.at(columnName)) != visited.end()) {
                throw FormulaException("The formulas form a cycle");
            }

            allVisited =
                this->_setPriority(priority, m_columnsByName.at(columnName),
                                   formulas, m_columnsByName, visited);
            allVisited.insert(idColumn);
        }
    }

    if (boost::range::find(priority, idColumn) == priority.end()) {
        priority.push_back(idColumn);
    }

    return allVisited;
}

DynamicValue *Table::_calculationFormula(
    std::map<unsigned int, DynamicValue> &rowValues,
    std::map<unsigned int, std::string> &nameColumns,
    std::map<unsigned int, DvType> &typeColumns, std::string formula) {
    VisitorCalcValue m_visitor(nameColumns, typeColumns, rowValues);

    BOOST_LOG_TRIVIAL(debug) << "Formula: " << formula;

    antlr4::ANTLRInputStream input(formula);
    CalcValueLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CalcValueParser parser(&tokens);

    //! Build ast tree
    antlr4::tree::ParseTree *tree = parser.parse();
    auto statement = m_visitor.visit(tree);

    return statement.as<DynamicValue *>();
}

void Table::recalculationRowValues(
    std::map<unsigned int, DynamicValue> &rowValues) {
    std::vector<unsigned int> priorityQueue =
        this->_getPriorityFormulas(this->_formulaColumns);

    BOOST_FOREACH (auto &idtable, priorityQueue) {
        auto value = this->_calculationFormula(rowValues, this->_nameColumns,
                                               this->_typeColumns,
                                               this->_formulaColumns[idtable]);

        if (this->_typeColumns.find(idtable) != this->_typeColumns.end()) {
            to_type(this->_typeColumns[idtable], (*value));
        }

        rowValues[idtable] = (*value);
    }
}

std::map<unsigned int, std::string> Table::_calculationColor(
    std::map<unsigned int, DynamicValue> &rowValues) {
    std::map<unsigned int, std::string> colorValues;

    BOOST_FOREACH (auto &m_pair, this->_colorColumns) {
        auto value = this->_calculationFormula(
            rowValues, this->_nameColumns, this->_typeColumns, m_pair.second);

        if (!(value->type == DvType::TYPE_OTHER ||
              value->type == DvType::TYPE_NONE)) {
            to_type(DvType::TYPE_STRING, (*value));
            colorValues[m_pair.first] =
                boost::any_cast<std::string>(value->value);
        }

        delete value;
    }

    return colorValues;
}

void Table::recalculationTree(
    TreeNode &node,
    const std::map<unsigned int, std::string> &aggregationColumns,
    unsigned int activeNode, bool isFindActiveNode) {
    if (!isFindActiveNode) {
        if (node.getIdPerson() == activeNode) isFindActiveNode = true;

        BOOST_FOREACH (auto &child_node, node.getChildren()) {
            this->recalculationTree(child_node, aggregationColumns, activeNode,
                                    isFindActiveNode);
        }
    }

    //! convolution number columns parant nodes
    this->_convolutionNode(node, aggregationColumns);

    //! calculate formulas
    this->_recalculationNode(node);

    //! calculate color
    this->_recalculationColorNode(node);

    //! update pyNode
    node.pyUpdate();
}

std::map<unsigned int, DynamicValue> Table::_getNodeValues(TreeNode &node) {
    std::map<unsigned int, DynamicValue> nodeValues;

    BOOST_FOREACH (auto &m_pair, node.getCells()) {
        nodeValues[m_pair.first] = m_pair.second.value;
    }

    return nodeValues;
}

void Table::_convolutionNode(
    TreeNode &node,
    const std::map<unsigned int, std::string> &aggregationColumns) {
    BOOST_FOREACH (auto &m_pair, aggregationColumns) {
        auto idColumn = m_pair.first;

        if (this->_formulaColumns.find(idColumn) != this->_formulaColumns.end())
            continue;

        std::map<unsigned int, DynamicValue> rowValues;
        std::map<unsigned int, std::string> nameColumns;
        std::map<unsigned int, DvType> typeColumns;
        std::vector<std::string> letters;

        letters_generator gen(ACII_LOWERCASE);
        boost::generator_iterator_generator<letters_generator>::type letter_it =
            boost::make_generator_iterator(gen);

        auto node_children = node.getChildren();

        //! gets column values of child rows for calc column value parent node
        for (int index = 0; index < node_children.size(); index++) {
            auto child_node = node_children[index];

            if (child_node.hasCell(idColumn)) {
                auto letter = *letter_it;
                letter_it++;
                letters.push_back(letter);
                rowValues.insert({index, child_node.getCell(idColumn).value});
                typeColumns.insert({index, this->_typeColumns[idColumn]});
                nameColumns.insert({index, letter});

                if (this->_unitColumns.find(idColumn) !=
                    this->_unitColumns.end()) {
                    CellValue m_cell = child_node.getCell(idColumn);
                    child_node.setCell(
                        idColumn, m_cell.value,
                        m_cell.repr + ' ' + this->_unitColumns[idColumn],
                        m_cell.color);
                }
            }
        }

        if (letters.size()) {
            //! build aggregation function
            std::string formula = m_pair.second;
            boost::replace_all(formula, "$values$",
                               boost::algorithm::join(letters, "; "));

            //! calc value and set in row
            auto value = this->_calculationFormula(rowValues, nameColumns,
                                                   typeColumns, formula);
            node.setCell(idColumn, (*value));
        }

        if (node.hasCell(idColumn)) {
            if (this->_unitColumns.find(idColumn) != this->_unitColumns.end()) {
                //! add unit in repr
                CellValue m_cell = node.getCell(idColumn);
                node.setCell(idColumn, m_cell.value,
                             m_cell.repr + ' ' + this->_unitColumns[idColumn],
                             m_cell.color);
            }
        }
    }
}

void Table::_recalculationNode(TreeNode &node) {
    auto node_children = node.getChildren();
    auto nodeValues = this->_getNodeValues(node);

    this->recalculationRowValues(nodeValues);

    BOOST_FOREACH (auto &m_pair, this->_formulaColumns) {
        if (!(nodeValues[m_pair.first].type == DvType::TYPE_NONE ||
              (!node_children.empty() &&
               this->_typeColumns[m_pair.first] != DvType::TYPE_NUMBER))) {
            node.setCell(m_pair.first, nodeValues[m_pair.first]);

            if (this->_unitColumns.find(m_pair.first) !=
                this->_unitColumns.end()) {
                //! add unit in repr
                CellValue m_cell = node.getCell(m_pair.first);
                node.setCell(
                    m_pair.first, m_cell.value,
                    m_cell.repr + ' ' + this->_unitColumns[m_pair.first],
                    m_cell.color);
            }
        }
    }
}

void Table::_recalculationColorNode(TreeNode &node) {
    auto node_children = node.getChildren();

    if (node_children.empty()) {
        //! node is leaf and the color is calculated from the formula
        auto nodeValues = this->_getNodeValues(node);

        BOOST_FOREACH (auto &m_pair, this->_calculationColor(nodeValues)) {
            if (node.hasCell(m_pair.first)) {
                node.setCell(m_pair.first, node.getCell(m_pair.first).value,
                             node.getCell(m_pair.first).repr, m_pair.second);
            }
        }
    } else {
        //! node is not leaf and the color is calculated by the priority
        //! of the colors of its child rows
        BOOST_FOREACH (auto &m_pair, this->_colorColumns) {
            if (this->_typeColumns[m_pair.first] == DvType::TYPE_NUMBER) {
                boost::optional<std::string> color = boost::none;
                boost::optional<int> priority_color = boost::none;

                BOOST_FOREACH (auto &child_node, node_children) {
                    if (child_node.hasCell(m_pair.first) &&
                        child_node.getCell(m_pair.first).color) {
                        auto child_cell = child_node.getCell(m_pair.first);
                        boost::optional<int> priority_child_color = boost::none;

                        if (this->_colorPriority.find(child_cell.color.get()) !=
                            this->_colorPriority.end())
                            priority_child_color =
                                this->_colorPriority[child_cell.color.get()];

                        if (priority_child_color != boost::none &&
                            priority_child_color > priority_color) {
                            priority_color = priority_child_color;
                            color = child_cell.color;
                        }
                    }
                }
                if (node.hasCell(m_pair.first)) {
                    node.setCell(m_pair.first, node.getCell(m_pair.first).value,
                                 node.getCell(m_pair.first).repr, color);
                }
            }
        }
    }
}
