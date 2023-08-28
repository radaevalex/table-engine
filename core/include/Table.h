#ifndef TABLE_ENGINE_TABLE_H
#define TABLE_ENGINE_TABLE_H

#include "TreeNode.h"
#include "VisitorCalcValue.h"
#include "engine.h"
#include "exception_collection.h"
#include "gen_calc_value/CalcValueLexer.h"

/**
 * Class is intended for calculating the values of computable columns,
 * convolution of values according to the formula
 * for the hierarchical structure of rows, calculating the color of the value
 * by formula and calculating their representation with a unit of measurement.
 */
class Table {
   public:
    /**
     * @param nameColumns - map where key - id column value - letters like 'A',
     * 'AA', 'AB'
     * @param typeColumns - map where key - id column value - id DvType like
     * 'A', 'AA', 'AB'
     * @param formulaColumns - map where key - id column value - formula
     * @param colorColumns - map where key - id column value - formula for
     * calculation column
     * @param colorPriority - map where key - hex color value - number priority
     * @param unitColumns - map where key - id column value - Unit of
     * measurement
     */
    explicit Table(
        const std::map<unsigned int, std::string> &nameColumns,
        const std::map<unsigned int, int> &typeColumns,
        const std::map<unsigned int, std::string> &formulaColumns = {},
        const std::map<unsigned int, std::string> &colorColumns = {},
        const std::map<std::string, int> &colorPriority = {},
        const std::map<unsigned int, std::string> &unitColumns = {});

    ~Table() = default;

    /**
     * Calculates the values of computable columns,
     * convolution of values according to the formula
     * calculates the color of the value by formula
     * and calculates their representation with a unit of measurement.
     *
     * @param node - object TreeNode
     * @param aggregationColumns - map where key - id column value - formula for convolution of values
     * @param activeNode - the key response_person is in the node from which
     * the calculations begin
     */
    TreeNode calculationTree(
        TreeNode node,
        std::map<unsigned int, std::string> aggregationColumns = {},
        unsigned int activeNode = NULL);

    /**
     * Calculates the values of computable columns
     *
     * @param rowValues - map where key - id column value - row value
     */
    std::map<unsigned int, DynamicValue> calculationRowValues(
        std::map<unsigned int, DynamicValue> rowValues);

    void recalculationTree(TreeNode &,
                           const std::map<unsigned int, std::string> & = {},
                           unsigned int = NULL, bool = false);
    void recalculationRowValues(std::map<unsigned int, DynamicValue> &);

   private:
    std::map<unsigned int, std::string> _nameColumns;
    std::map<unsigned int, DvType> _typeColumns;
    std::map<unsigned int, std::string> _formulaColumns;
    std::map<unsigned int, std::string> _colorColumns;
    std::map<std::string, int> _colorPriority;
    std::map<unsigned int, std::string> _unitColumns;
    std::vector<unsigned int> _numberColumns;

    /**
     * Calculates value by formula
     *
     * @param rowValues - map where key - id column value - row value
     * @param nameColumns - map where key - id column value - letters like 'A',
     * 'AA', 'AB'
     * @param formula - formula string
     */
    DynamicValue *_calculationFormula(
        std::map<unsigned int, DynamicValue> &rowValues,
        std::map<unsigned int, std::string> &,
        std::map<unsigned int, DvType> &nameColumns, std::string formula);

    /**
     * Returns a vector of indifiers whose position corresponds to the priority
     * of calculating formulas
     *
     * @param formulas - Map where key - indifier column , value - formula
     */
    std::vector<unsigned int> _getPriorityFormulas(
        const std::map<unsigned int, std::string> &formulaColumns);

    /**
     * Insert indifer column into vector by priority
     *
     * @param priority - Vector priority
     * @param idColumn - indifier column
     * @param formulas - map where key - indifier column , value - formula
     * @param m_columnsByName - map where key - name column value - id column
     * indifier
     * @param visited - Visited columns
     * @return - All visited columns
     */
    std::set<unsigned int> _setPriority(
        std::vector<unsigned int> &priority, unsigned int idColumn,
        const std::map<unsigned int, std::string> &formulas,
        const std::map<std::string, unsigned int> &m_columnsByName,
        std::set<unsigned int> visited = std::set<unsigned int>());

    /**
     * calculates the color of the value by formula
     *
     * @param rowValues - map where key - id column value - row value
     */
    std::map<unsigned int, std::string> _calculationColor(
        std::map<unsigned int, DynamicValue> &rowValues);

    /**
     * Returns row values from node
     */
    std::map<unsigned int, DynamicValue> _getNodeValues(TreeNode &node);

    /**
     * Calculates the values of computable columns,
     * convolution of values according to the formula
     *
     * @param node - node
     * @param aggregationColumns - map where key - id column value - formula in
     * which the substring 'values' must be present to replace it with values
     */
    void _convolutionNode(
        TreeNode &node,
        const std::map<unsigned int, std::string> &aggregationColumns = {});

    /**
     * Calculates the values of computable columns in node
     */
    void _recalculationNode(TreeNode &node);

    /**
     * Calculates the color of the values by formula in node
     */
    void _recalculationColorNode(TreeNode &node);
};

#endif  // TABLE_ENGINE_TABLE_H
