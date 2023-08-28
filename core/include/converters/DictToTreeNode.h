#ifndef TABLE_ENGINE_DICTTOTREENODE_H
#define TABLE_ENGINE_DICTTOTREENODE_H

#include "TreeNode.h"
#include "engine.h"

class DictToTreeNode {
   public:
    explicit DictToTreeNode() {
        py::converter::registry::push_back(&DictToTreeNode::convertible,
                                           &DictToTreeNode::construct,
                                           py::type_id<TreeNode>());

        py::to_python_converter<TreeNode, DictToTreeNode>();
    }

    static void *convertible(PyObject *py_object) {
        if (!PyMapping_Check(py_object)) return nullptr;
        return py_object;
    }

    static void construct(PyObject *py_object,
                          py::converter::rvalue_from_python_stage1_data *data) {
        //! Placing an object in allocated memory (Replaced New)
        auto storage = new (
            reinterpret_cast<
                py::converter::rvalue_from_python_storage<TreeNode> *>(data)
                ->storage.bytes) TreeNode;
        //! Serialize new values
        try {
            fillMapFromDict(py_object, storage);
        } catch (std::exception e) {
            delete storage;
            throw ConverterException(e.what());
        }

        data->convertible = storage;
    }

    static void fillMapFromDict(PyObject *py_object, TreeNode *const storage) {
        (*storage) = TreeNode(py_object);

        if (PyMapping_HasKeyString(py_object, "children")) {
            PyObject *py_children =
                PyMapping_GetItemString(py_object, "children");
            auto size = PySequence_Size(py_children);

            for (py::ssize_t j = 0, k = size; j < k; ++j) {
                TreeNode child_node;
                DictToTreeNode::fillMapFromDict(
                    PySequence_GetItem(py_children, j), &child_node);

                storage->addChild(child_node);
            }
        }
    }

    static PyObject *convert(TreeNode node) {
        try {
            return py::incref(node.getPyNode());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_DICTTOTREENODE_H
