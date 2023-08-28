#include "engine.h"

#include <boost/python/raw_function.hpp>

#include "Table.h"
#include "converters/DictToMap.h"
#include "converters/DictToMapDynamicValue.h"
#include "converters/DictToMapMap.h"
#include "converters/DictToTreeNode.h"
#include "converters/ListToVector.h"
#include "converters/ListToVectorDynamicValue.h"
#include "converters/RegisterException.h"
#include "converters/ToDynamicValue.h"
#include "exception_collection.h"

BOOST_PYTHON_MODULE(table_engine) {
    py::class_<Table>(
        "Table",
        py::init<
            std::map<unsigned int, std::string>, std::map<unsigned int, int>,
            std::map<unsigned int, std::string>,
            std::map<unsigned int, std::string>, std::map<std::string, int>,
            std::map<unsigned int, std::string>>())
        .def("recalculation_tree", &Table::calculationTree,
             (py::arg("aggregationColumns"), py::arg("activeNode") = NULL))
        .def("calculation_row_values", &Table::calculationRowValues);

    //! Registration converters
    ListToVector<std::vector<double>>();
    ListToVector<std::vector<int>>();
    ListToVector<std::vector<std::string>>();

    DictToMap<std::map<std::string, std::string>>();
    DictToMap<std::map<std::string, int>>();
    DictToMap<std::map<int, std::string>>();
    DictToMap<std::map<int, int>>();
    DictToMap<std::map<int, cpp_dec_float_50>>();
    DictToMap<std::map<unsigned int, std::string>>();
    DictToMap<std::map<unsigned int, int>>();
    DictToMap<std::map<unsigned int, cpp_dec_float_50>>();
    DictToMapMap<std::map<std::string, std::map<std::string, std::string>>>();

    ToDynamicValue();
    ListToVectorDynamicValue();
    DictToMapDynamicValue<unsigned int>();

    DictToTreeNode();

    RegisterException<EngineException>("EngineException");
    RegisterException<FormulaException>("FormulaException");
    RegisterException<ConverterException>("ConverterException");
}
