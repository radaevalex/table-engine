import copy
import math
import unittest

import table_engine
from . import data


class CatchNan:
    def __index__(self):
        pass

    def __eq__(self, other):
        return math.isnan(other)


class TableEngineTest(unittest.TestCase):
    def test_calculation_tree(self):
        table_obj = table_engine.Table(
            data.T1_NAME_COLUMNS,
            data.T1_TYPE_COLUMNS,
            data.T1_FORMULA_COLUMNS,
            data.T1_COLOR_COLUMNS,
            data.T1_COLUMN_COLOR_PRIORITY,
            data.T1_UNIT_COLUMNS
        )

        res = copy.deepcopy(data.T1_TEST_TREE)

        # makes calculations
        table_obj.recalculation_tree(res, data.T1_AGGREGATION_COLUMNS)

        self.assertEqual(res, data.T1_RIGHT_TEST_TREE_AFTER_RECALC)

        # checks with arg active_node
        res = copy.deepcopy(data.T1_TEST_TREE)

        # makes calculations
        table_obj.recalculation_tree(res, data.T1_AGGREGATION_COLUMNS, 85000000)

        # check results
        self.assertEqual(res, data.T1_RIGHT_TEST_TREE_AFTER_RECALC_2)

    def test_calculation_row_values(self):
        table_obj = table_engine.Table(
            data.T2_NAME_COLUMNS,
            data.T2_TYPE_COLUMNS,
            data.T2_FORMULA_COLUMNS
        )

        # makes calculations
        row_values = table_obj.calculation_row_values(data.T2_ROW_VALUES)

        # check results
        self.assertEqual(row_values, data.T2_RIGHT_ROW_VALUES_AFTER_CALC)
