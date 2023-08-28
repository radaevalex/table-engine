#ifndef TABLE_ENGINE_TREENODE_H
#define TABLE_ENGINE_TREENODE_H

#include "converters/ListToVectorDynamicValue.h"
#include "converters/ToDynamicValue.h"
#include "engine.h"
#include "exception_collection.h"

/**
 * Tree node object that takes an python object of the following form:
 * {
 *      'response_person': 85020100,
 *      '41': {'value': [15], 'repr': '0', 'expression': None},
 *      '54': {'value': ['10'], 'repr': '0', 'expression': None},
 *      '62': {'value': ['HELLO'], 'repr': 'HELLO'},
 *      '72': {'value': [' WORLD'], 'repr': ' WORLD'},
 *      "id": "9bfd09c2-0d06-46f6-a6d6-29688323be25",
 *      'children': [],
 * }
 */
class TreeNode {
   public:
    TreeNode(){};
    TreeNode(PyObject* pyNode);

    /**
     * Returns all cells in tree node
     */
    const std::map<unsigned int, CellValue>& getCells();
    /**
     * Returns cell by id
     */
    const CellValue& getCell(unsigned int idColumn);
    /**
     * Checks whether there is cell in the tree node with this idColumn
     */
    bool hasCell(unsigned int idColumn);
    /**
     * Adds cell to the Tree nada if it does not exist or updates it
     * @param idColumn - Id cell
     * @param value - value
     * @param repr - value representation
     * @param color - color cell
     */
    void setCell(unsigned int idColumn, DynamicValue value,
                 boost::optional<std::string> repr = boost::none,
                 boost::optional<std::string> color = boost::none);
    /**
     * Makes all changes to _pyNode
     */
    void pyUpdate();
    /**
     * adds a node to the list of children
     * @param node - child node
     */
    void addChild(TreeNode node);

    unsigned int getIdPerson();
    PyObject* getPyNode();
    std::vector<TreeNode>& getChildren();

   private:
    PyObject* _pyNode;
    std::vector<TreeNode> _children;
    std::map<unsigned int, CellValue> _cells;
    std::set<unsigned int> _needUpdateCells;
    unsigned int _idPerson;

    /**
     * Makes all changes to Python cell object
     * @param py_cell - Python cell object
     * @param rcell - cell object
     */
    void _fillCell(PyObject* py_cell, CellValue& rcell);
    /**
     * Returns value representation
     */
    std::string _getRepr(DynamicValue rvalue);
};

#endif  // TABLE_ENGINE_TREENODE_H
