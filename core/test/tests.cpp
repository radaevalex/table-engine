#define BOOST_AUTO_TEST_MAIN

#include <boost/test/unit_test.hpp>

#include "Table.h"
#include "converters/DictToMapDynamicValue.h"
#include "converters/DictToMapMap.h"
#include "converters/DictToTreeNode.h"

BOOST_AUTO_TEST_SUITE(TestTable)

BOOST_AUTO_TEST_CASE(RecalculationRowValues) {
    std::map<unsigned int, std::string> nameColumns{
        {10000001, "AAA"}, {10000002, "AAB"}, {1, "A"},   {2, "B"},
        {3, "C"},          {4, "E"},          {5, "F"},   {6, "G"},
        {7, "H"},          {8, "I"},          {9, "J"},   {10, "K"},
        {11, "L"},         {12, "M"},         {13, "N"},  {14, "O"},
        {15, "P"},         {16, "R"},         {17, "S"},  {18, "T"},
        {19, "U"},         {20, "V"},         {21, "W"},  {22, "X"},
        {23, "Y"},         {24, "Z"},         {25, "AA"}, {26, "AB"},
        {27, "AC"},        {28, "AD"},        {29, "AE"}, {30, "AF"},
        {31, "AG"},        {32, "AH"}};
    std::map<unsigned int, int> typeColumns{{10000001, DvType::TYPE_DATE},
                                            {10000002, DvType::TYPE_DATETIME},
                                            {1, DvType::TYPE_NUMBER},
                                            {2, DvType::TYPE_NUMBER},
                                            {3, DvType::TYPE_NUMBER},
                                            {4, DvType::TYPE_NUMBER},
                                            {5, DvType::TYPE_NUMBER},
                                            {6, DvType::TYPE_NUMBER},
                                            {7, DvType::TYPE_NUMBER},
                                            {8, DvType::TYPE_NUMBER},
                                            {9, DvType::TYPE_NUMBER},
                                            {10, DvType::TYPE_STRING},
                                            {11, DvType::TYPE_NUMBER},
                                            {12, DvType::TYPE_NUMBER},
                                            {13, DvType::TYPE_NUMBER},
                                            {14, DvType::TYPE_DATETIME},
                                            {15, DvType::TYPE_DATETIME},
                                            {16, DvType::TYPE_NUMBER},
                                            {17, DvType::TYPE_NUMBER},
                                            {18, DvType::TYPE_NUMBER},
                                            {19, DvType::TYPE_BOOLEAN},
                                            {20, DvType::TYPE_NUMBER},
                                            {21, DvType::TYPE_STRING},
                                            {22, DvType::TYPE_STRING},
                                            {23, DvType::TYPE_STRING},
                                            {24, DvType::TYPE_NUMBER},
                                            {25, DvType::TYPE_NUMBER},
                                            {26, DvType::TYPE_STRING},
                                            {27, DvType::TYPE_NUMBER},
                                            {28, DvType::TYPE_STRING},
                                            {29, DvType::TYPE_DATETIME},
                                            {30, DvType::TYPE_STRING},
                                            {31, DvType::TYPE_NUMBER},
                                            {32, DvType::TYPE_NUMBER}

    };

    if (!Py_IsInitialized()) {
        BOOST_LOG_TRIVIAL(debug) << "Initilaze python interpritator";
        Py_Initialize();
    }

    PyDateTime_IMPORT;

    //! python dict that is row values
    auto py_date_value = boost::python::handle<>(
        boost::python::borrowed(PyDate_FromDate(2012, 2, 2)));
    auto py_datetime_value = boost::python::handle<>(boost::python::borrowed(
        PyDateTime_FromDateAndTime(2012, 2, 2, 12, 3, 33, NULL)));
    py::list values1;
    values1.append("22");

    py::list values2;
    values2.append(12);
    values2.append(32);

    py::dict pyRowValues;
    pyRowValues[1] = values1;
    pyRowValues[2] = values2;
    pyRowValues[10000001] = py_date_value;
    pyRowValues[10000002] = py_datetime_value;

    py::dict formulaColumns;
    formulaColumns[3] = "=E+3";
    formulaColumns[4] = "=A+4";
    formulaColumns[5] = "=C+E";
    formulaColumns[6] = "=C*E";
    formulaColumns[7] = "=G/E";
    formulaColumns[8] = "=sum(A;B;C;E;1)";
    formulaColumns[9] = "=count(A;B;C;E;1)";
    formulaColumns[10] =
        "=textjoin(\".\";1;day(date(2012;2;2));month(date(2012;2;2));year(date("
        "2012;2;2)))";
    formulaColumns[11] = "=year(date(2012;2;2))";
    formulaColumns[12] = "=month(date(2012;2;2))";
    formulaColumns[13] = "=day(date(2012;2;2))";
    formulaColumns[14] = "=(now()-now())+1";
    formulaColumns[15] = "=today()*0+1";
    formulaColumns[16] = "=weekday(date(2012;2;2))";
    formulaColumns[17] = "=weekday(date(2012;2;2);2)";
    formulaColumns[18] = "=weekday(date(2012;2;2);1)";
    formulaColumns[19] = "=and(true;not(not(\"34\"));not(false))";
    formulaColumns[20] =
        "=if(or(today()<date(2012;2;2);(2>3));weekday(date(2012;2;2);2);year("
        "date(2012;2;2)))";
    formulaColumns[21] = "=textjoin(\",\";0;\"22\";\"\";4;\"dsdss\")";
    formulaColumns[22] = "=textjoin(\",\";1;\"22\";\"\";4;\"dsdss\")";
    formulaColumns[23] = "=choose(\"2\";3;\"5\";10)";
    formulaColumns[24] = "=switch(5;32;3;2;10;228)";
    formulaColumns[25] = "=switch(\"2\";32;3;2;10;228)";
    formulaColumns[26] = "=concat(2.3;1;23;\"2.3\";3;2;\"dfdfd\")";
    formulaColumns[27] = "=day(AAA+3)";
    formulaColumns[28] =
        "=textjoin(\":\";1;hour(time(1;3;2));minute(time(1;3;2));second(time(1;"
        "3;2)))";
    formulaColumns[29] = "=hour(time(1;3;2))+minute(time(1;3;2))";
    formulaColumns[30] =
        "=concat("
        "textjoin(\".\";1;day(date(2022;2;2)+time(2;3;2));month(date(2022;2;2)+"
        "time(2;3;2));year(date(2022;2;2)+time(2;3;2)));"
        "\" \";"
        "textjoin(\":\";1;hour(date(2022;2;2)+time(2;3;2));minute(date(2022;2;"
        "2)+time(2;3;2));second(date(2022;2;2)+time(2;3;2))))";
    formulaColumns[31] = "=if(0;2;)";
    formulaColumns[32] = "=ifs(5<4;10;5>3;22)";
    formulaColumns[33] = "=average(5;10;7;22)";
    formulaColumns[34] = "=min(5;10;7;22)";
    formulaColumns[35] = "=max(5;10;7;22)";
    formulaColumns[36] = "=median(5;10;22;7)";
    formulaColumns[37] = "=median(5;10;22;1;7)";

    std::map<unsigned int, DynamicValue> rowValues;
    std::map<unsigned int, std::string> mapformuls;

    //! check converter py dict to map
    DictToMapDynamicValue<unsigned int>::fillMapFromDict(pyRowValues.ptr(),
                                                         &rowValues);
    DictToMap<std::map<unsigned int, std::string>>::fillMapFromDict(
        formulaColumns.ptr(), &mapformuls);

    //! makes calculations
    Table tableObj(nameColumns, typeColumns, mapformuls);
    tableObj.recalculationRowValues(rowValues);

    //! check results
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[3].value),
                        cpp_dec_float_50(29));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[4].value),
                        cpp_dec_float_50(26));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[5].value),
                        cpp_dec_float_50(55));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[6].value),
                        cpp_dec_float_50(754));
    BOOST_REQUIRE_EQUAL(
        boost::lexical_cast<std::string>(
            boost::any_cast<cpp_dec_float_50>(rowValues[7].value)),
        "29");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[8].value),
                        cpp_dec_float_50(122));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[9].value),
                        cpp_dec_float_50(5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[10].value),
                        "2.2.2012");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[11].value),
                        cpp_dec_float_50(2012));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[12].value),
                        cpp_dec_float_50(2));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[13].value),
                        cpp_dec_float_50(2));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[14].value),
                        cpp_dec_float_50(86400));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[15].value),
                        cpp_dec_float_50(1));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[16].value),
                        cpp_dec_float_50(5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[17].value),
                        cpp_dec_float_50(4));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[18].value),
                        cpp_dec_float_50(5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[19].value),
                        cpp_dec_float_50(1));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[20].value),
                        cpp_dec_float_50(2012));
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[21].value),
                        "22,,4,dsdss");
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[22].value),
                        "22,4,dsdss");
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[23].value), "5");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[24].value),
                        cpp_dec_float_50(228));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[25].value),
                        cpp_dec_float_50(10));
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[26].value),
                        "2.31232.332dfdfd");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[27].value),
                        cpp_dec_float_50(5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[28].value),
                        "1:3:2");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[29].value),
                        cpp_dec_float_50(4));
    BOOST_REQUIRE_EQUAL(boost::any_cast<std::string>(rowValues[30].value),
                        "2.2.2022 2:3:2");
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[32].value),
                        cpp_dec_float_50(22));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[33].value),
                        cpp_dec_float_50(11));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[34].value),
                        cpp_dec_float_50(5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[35].value),
                        cpp_dec_float_50(22));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[36].value),
                        cpp_dec_float_50(8.5));
    BOOST_REQUIRE_EQUAL(boost::any_cast<cpp_dec_float_50>(rowValues[37].value),
                        cpp_dec_float_50(7));

    //! check converter map to py dict
    DictToMapDynamicValue<unsigned int>::convert(rowValues);
}

BOOST_AUTO_TEST_CASE(RecalculationTree) {
    if (!Py_IsInitialized()) {
        BOOST_LOG_TRIVIAL(debug) << "Initilaze python interpritator";
        Py_Initialize();
    }

    //! python dict that is tree
    py::dict column41;
    py::list values41;
    values41.append("9");
    column41["value"] = values41;
    column41["expression"] = NULL;

    py::dict column54;
    py::list values54;
    values54.append(2);
    values54.append(2.5);
    column54["value"] = values54;
    column54["repr"] = py::object("2232");
    column54["expression"] = "dsafds";

    py::dict column52;
    py::list values52;
    column52["value"] = values52;

    py::dict py_tree;

    py_tree["response_person"] = 10000000;

    py::dict parent;

    parent["response_person"] = 85000000;

    py::list childList;
    py::dict child;

    child["response_person"] = 85020000;
    child["id"] = "9bfd09c2-0d06-46f6-a6d6-29688d83be25";
    child["41"] = column41;
    child["54"] = column54;
    child["52"] = column52;
    child["62"] = column52;

    child["children"] = py::list();
    py::dict child1;
    child1["response_person"] = 85010000;
    child1["id"] = "9bfd09c2-0d06-46f6-a6d6-29688d83be25";
    child1["41"] = column41;
    child1["54"] = column54;
    child1["52"] = column52;
    child1["62"] = column52;
    child1["children"] = py::list();

    //    test filled not all columns
    py::dict child2;
    child2["response_person"] = 85010000;
    child2["id"] = "9bfd09c2-0d06-46f6-a6d6-29688d83be25";
    child2["41"] = column41;
    child2["children"] = py::list();

    childList.append(child);
    childList.append(child1);
    childList.append(child2);

    parent["children"] = childList;

    py::list super_parend_child;
    super_parend_child.append(parent);
    py_tree["children"] = super_parend_child;

    //! table properties
    std::map<unsigned int, std::string> nameColumns{
        {41, "A"}, {54, "B"}, {52, "C"}, {62, "E"}, {72, "F"}};
    std::map<unsigned int, int> typeColumns{{41, DvType::TYPE_NUMBER},
                                            {54, DvType::TYPE_NUMBER},
                                            {52, DvType::TYPE_NUMBER},
                                            {62, DvType::TYPE_NUMBER},
                                            {72, DvType::TYPE_NUMBER}};
    std::map<unsigned int, std::string> formulaColumns = {{52, "=A+B"}};

    std::map<unsigned int, std::string> colorColumns = {
        {52, "=if(C>15;if(C<31;\"#008000\";\"#0000FF\");)"}};
    std::map<std::string, int> colorPriority = {{"#0000FF", 0}, {"#008000", 1}};
    std::map<unsigned int, std::string> unitColumns = {{52, "%"}};
    std::map<unsigned int, std::string> aggregationColumns = {
        {41, "=sum($values$)"},
        {54, "=sum($values$)"},
        {52, "=sum($values$)"},
        {62, "=sum($values$)"},
        {72, "=sum($values$)"}};

    Table tableObj(nameColumns, typeColumns, formulaColumns, colorColumns,
                   colorPriority, unitColumns);

    //! check converter py dict to class TreeNode
    TreeNode node;
    DictToTreeNode::fillMapFromDict(py_tree.ptr(), &node);

    //! makes calculations
    tableObj.recalculationTree(node, aggregationColumns);

    //! check results
    BOOST_REQUIRE_EQUAL(
        boost::any_cast<cpp_dec_float_50>(node.getCell(52).value.value),
        cpp_dec_float_50(36));
    BOOST_REQUIRE_EQUAL(node.getCell(52).repr, "36 %");
    BOOST_REQUIRE_EQUAL(
        boost::any_cast<cpp_dec_float_50>(node.getCell(41).value.value),
        cpp_dec_float_50(27));
    BOOST_REQUIRE_EQUAL(
        boost::any_cast<cpp_dec_float_50>(node.getCell(54).value.value),
        cpp_dec_float_50(9));

    //! check converter class TreeNode to py dict
    DictToTreeNode::convert(node);
    DictToTreeNode::fillMapFromDict(DictToTreeNode::convert(node), &node);
}

BOOST_AUTO_TEST_SUITE_END()
