#include "TreeNode.h"

TreeNode::TreeNode(PyObject *pyNode) : _pyNode(pyNode) {
    if (!PyMapping_Check(pyNode)) {
        throw ConverterException("Passed python object is not a dict");
    }

    auto keys = PyMapping_Keys(pyNode);

    for (py::ssize_t i = 0, l = PySequence_Size(keys); i < l; ++i) {
        std::string key = py::extract<std::string>(PySequence_GetItem(keys, i));
        auto py_cell = PyObject_GetItem(pyNode, PySequence_GetItem(keys, i));

        if (key == "response_person") {
            this->_idPerson = py::extract<unsigned int>(py_cell)();
        } else if (std::all_of(key.begin(), key.end(), ::isdigit) &&
                   PyMapping_HasKeyString(py_cell, "value")) {
            auto idColumn = boost::lexical_cast<unsigned int>(key);
            auto value = ToDynamicValue::getValue(
                PyMapping_GetItemString(py_cell, "value"));

            if (value.type == DvType::TYPE_OTHER ||
                value.type == DvType::TYPE_NONE)
                continue;

            std::string repr;
            boost::optional<std::string> color;

            if (PyMapping_HasKeyString(py_cell, "repr") &&
                PyMapping_GetItemString(py_cell, "repr") != Py_None) {
                repr = py::extract<std::string>(
                    PyMapping_GetItemString(py_cell, "repr"));
            } else {
                repr = this->_getRepr(value);
                this->_needUpdateCells.insert(idColumn);
            }

            if (PyMapping_HasKeyString(py_cell, "color") &&
                PyMapping_GetItemString(py_cell, "color") != Py_None) {
                color = py::extract<std::string>(
                    PyMapping_GetItemString(py_cell, "color"));
            }

            CellValue rcell;
            rcell.value = value;
            rcell.repr = repr;
            rcell.color = color;

            this->_cells[idColumn] = rcell;
        }
    }
}

const std::map<unsigned int, CellValue> &TreeNode::getCells() {
    return this->_cells;
}

const CellValue &TreeNode::getCell(unsigned int idColumn) {
    if (!this->hasCell(idColumn))
        throw ConverterException("There is no cell with this id");

    return this->_cells[idColumn];
}

bool TreeNode::hasCell(unsigned int idColumn) {
    return this->_cells.find(idColumn) != this->_cells.end();
}

void TreeNode::setCell(unsigned int idColumn, DynamicValue value,
                       boost::optional<std::string> repr,
                       boost::optional<std::string> color) {
    CellValue cell;
    cell.value = value;
    cell.repr = (repr != boost::none) ? repr.get() : this->_getRepr(value);
    cell.color = color;
    this->_cells[idColumn] = cell;
    this->_needUpdateCells.insert(idColumn);
}

void TreeNode::pyUpdate() {
    try {
        BOOST_FOREACH (auto &idColumn, this->_needUpdateCells) {
            if (!this->hasCell(idColumn)) continue;

            PyObject *py_cell;
            std::string key = std::to_string(idColumn);

            if (PyMapping_HasKeyString(this->_pyNode, key.c_str())) {
                py_cell = PyMapping_GetItemString(this->_pyNode, key.c_str());
            } else {
                py_cell = py::incref(py::dict().ptr());
                PyMapping_SetItemString(this->_pyNode, key.c_str(), py_cell);
            }

            this->_fillCell(py_cell, this->_cells[idColumn]);
        }
    } catch (std::exception e) {
        throw ConverterException(e.what());
    }
}

void TreeNode::addChild(TreeNode node) {
    this->_children.push_back(node);
}

void TreeNode::_fillCell(PyObject *py_cell, CellValue &rcell) {
    DynamicValue value = rcell.value;
    std::string repr = rcell.repr;
    boost::optional<std::string> color = rcell.color;

    if (value.type != DvType::TYPE_STRING) {
        value.type = DvType::TYPE_NUMBER;
    }

    std::vector<DynamicValue> list_value = {value};
    PyMapping_SetItemString(
        py_cell, "value", ListToVectorDynamicValue::toObject(list_value).ptr());
    PyMapping_SetItemString(py_cell, "repr", py::object(repr).ptr());
    PyMapping_SetItemString(
        py_cell, "color",
        ((color != boost::none) ? py::object(color.get()).ptr() : Py_None));
}

std::string TreeNode::_getRepr(DynamicValue rvalue) {
    if (rvalue.type == DvType::TYPE_DATETIME) {
        time_t time_value =
            (int)boost::any_cast<cpp_dec_float_50>(rvalue.value);
        std::stringstream ss;

        ss << std::put_time(std::localtime(&time_value), "%d.%m.%Y %H:%M:%S");

        return ss.str();
    } else if (rvalue.type == DvType::TYPE_DATE) {
        time_t time_value =
            (int)boost::any_cast<cpp_dec_float_50>(rvalue.value);
        std::stringstream ss;

        ss << std::put_time(std::localtime(&time_value), "%d.%m.%Y");

        return ss.str();
    } else if (rvalue.type == DvType::TYPE_TIME) {
        time_t time_value =
            (int)boost::any_cast<cpp_dec_float_50>(rvalue.value);
        std::stringstream ss;

        ss << std::put_time(std::localtime(&time_value), "%H:%M:%S");

        return ss.str();
    } else if (rvalue.type == DvType::TYPE_STRING) {
        return boost::any_cast<std::string>(rvalue.value);
    } else if (rvalue.type == DvType::TYPE_NUMBER) {
        auto value = static_cast<long double>(
            boost::any_cast<cpp_dec_float_50>(rvalue.value));

        if (static_cast<int>(value) == value) {
            return (boost::format("%d") % value).str();
        }

        return (boost::format("%.2f") % value).str();
    } else if (rvalue.type == DvType::TYPE_NONE) {
        return "";
    } else {
        return "N/A";
    }
}

unsigned int TreeNode::getIdPerson() { return this->_idPerson; }
PyObject *TreeNode::getPyNode() { return this->_pyNode; }
std::vector<TreeNode> &TreeNode::getChildren() { return this->_children; }