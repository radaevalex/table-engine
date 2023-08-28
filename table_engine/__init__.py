from functools import wraps
import types
from typing import Dict, Callable, Any

from .exceptions import (
    LibError,
    EngineError,
    ImportLibError,
    AttributeLibError,
    FormulaLibError,
    ConverterError
)

try:
    from .libs import table_engine
except ImportError as err:
    msg = "Error: import shared lib 'table_engine'" + '\n' + str(err)
    raise ImportLibError(msg)

# TYPES
NUMBER_TYPE = 1
STRING_TYPE = 2
BOOLEAN_TYPE = 3
TIME_TYPE = 4
DATE_TYPE = 5
DATETIME_TYPE = 6


def func_catch_exception(func: Callable) -> Callable:
    """
    Wraps a function to handle exceptions
    """

    @wraps(func)
    def wrapper(*args, **kwargs):
        try:
            res = func(*args, **kwargs)
        except AttributeError as err:
            raise AttributeLibError(str(err))
        except table_engine.EngineException as err:
            raise EngineError(str(err))
        except table_engine.FormulaException as err:
            raise FormulaLibError(str(err))
        except table_engine.ConverterException as err:
            raise ConverterError(str(err))
        except Exception as err:
            raise LibError(str(err))

        return res

    return wrapper


def class_catch_exception(cls: object) -> object:
    """
    Wraps a class to handle exceptions
    """

    def dec_getattribute(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            res = func(*args, **kwargs)

            if type(res) == types.MethodType:
                return func_catch_exception(res)
            else:
                return res

        return wrapper

    cls.__getattribute__ = dec_getattribute(cls.__getattribute__)
    return cls


# classes
@class_catch_exception
class Table:
    """
    Class is intended for calculating the values of computable columns,
    convolution of values according to the formula
    for the hierarchical structure of rows, calculating the color of the value
    by formula and calculating their representation with a unit of measurement.
    """

    def __init__(self, name_columns: Dict[int, str],
                 type_columns: Dict[int, int],
                 formula_columns: Dict[int, str] = None,
                 color_columns: Dict[int, str] = None,
                 column_color_priority: Dict[str, int] = None,
                 unit_columns: Dict[int, str] = None):
        """
        :param name_columns: dict where key - id column value - letters like 'A', 'AA', 'AB', 'AAA' ..
        :param type_columns: dict where key - id column value - id type column value (NUMBER_TYPE | STRING_TYPE |
        BOOLEAN_TYPE | TIME_TYPE | DATE_TYPE | DATETIME_TYPE)
        :param formula_columns: dict where key - id computable column value - formula
        :param color_columns: dict where key - id column value - formula that hex calculate color
        :param column_color_priority: dict where key - hex column value - number priority
        :param unit_columns: dict where key - id column value - unit of measurement
        """
        self.__name_columns = name_columns
        self.__type_columns = type_columns
        self.__column_formulas = formula_columns
        self.__color_columns = color_columns
        self.__column_color_priority = column_color_priority
        self.__unit_columns = unit_columns

        self.__table_obj = table_engine.Table(
            name_columns, type_columns,
            (formula_columns if formula_columns is not None else {}),
            (color_columns if color_columns is not None else {}),
            (column_color_priority if column_color_priority is not None else {}),
            (unit_columns if unit_columns is not None else {})
        )

    def recalculation_tree(self, tree: Dict[str, Any],
                           aggregation_columns: Dict[int, str] = None, active_node: int = None) -> None:
        """
        Calculates the values of computable columns, convolution of values according to the formula
        calculates the color of the value by formula and calculates their representation with a unit of measurement.

        :param tree: dict where 'response_person' key is required and values of the columns are represented
        as the key of the id column and the value is a dict of the form '"54": {"value": ..., "repr": ..., "color": ...}'
        where "value" is required. Example:
        {
            "response_person": 10000000,
            "children": [
                {
                    "response_person": 85020100,
                    "41": {"value": [15], "repr": "0", "expression": None},
                    "54": {"value": ["10"], "repr": "0", "expression": None},
                    "62": {"value": ["HELLO"], "repr": "HELLO"},
                }
            ]
        }
        :param aggregation_columns: dict where key - id column value - formula for convolution of values
        :param active_node: the key response_person is in the node from which the calculations begin
        """
        if active_node is None:
            self.__table_obj.recalculation_tree(
                tree,
                aggregationColumns=(aggregation_columns if aggregation_columns is not None else {})
            )
        else:
            self.__table_obj.recalculation_tree(
                tree,
                aggregationColumns=(aggregation_columns if aggregation_columns is not None else {}),
                activeNode=active_node
            )

    def calculation_row_values(self, row_values: Dict[int, Any]) -> Dict[int, Any]:
        """
        Calculates the values of computable columns

        :param row_values: dict where key - id column value - column value
        """
        return self.__table_obj.calculation_row_values(row_values)

    def __repr__(self):
        repr = '{}({!r}, {!r}, {!r}, {!r}, {!r}, {!r})'.format(
            self.__class__.__name__,
            self.__name_columns,
            self.__type_columns,
            self.__formula_columns,
            self.__color_columns,
            self.__column_color_priority,
            self.__unit_columns
        )

        return repr
