import datetime
from table_engine import NUMBER_TYPE, STRING_TYPE, DATE_TYPE, DATETIME_TYPE, BOOLEAN_TYPE, TIME_TYPE

# data for test calculation tree (T1)

T1_NAME_COLUMNS = {
    41: "A",
    54: "B",
    52: "C",
    62: "E",
    72: "F",
    82: "G"
}

T1_TYPE_COLUMNS = {
    41: NUMBER_TYPE,
    54: NUMBER_TYPE,
    52: NUMBER_TYPE,
    62: STRING_TYPE,
    72: STRING_TYPE,
    82: STRING_TYPE
}

T1_FORMULA_COLUMNS = {
    52: "=A+B",
    82: "=concat(E;F)"
}

T1_COLOR_COLUMNS = {52: "=if(C>15;if(C<31;\"#008000\";);\"#0000FF\")"}

T1_COLUMN_COLOR_PRIORITY = {
    "#0000FF": 0,
    "#008000": 1
}

T1_UNIT_COLUMNS = {52: "%"}

T1_AGGREGATION_COLUMNS = {
    41: "=average($values$)",
    54: "=min($values$)",
    62: "=textjoin(\" \";true;$values$)"
}

T1_TEST_TREE = {
    "response_person": 10000000,
    "children": [
        {
            "response_person": 85000000,
            "children": [
                {
                    "response_person": 85020000,
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be25",
                    "children": [
                        {
                            "response_person": 85020100,
                            "41": {"value": [15], "repr": "0", "expression": None},
                            "54": {"value": ["10"], "repr": "0", "expression": None},
                            "62": {"value": ["HELLO"], "repr": "HELLO"},
                            "72": {"value": [" WORLD"], "repr": " WORLD"},
                            "id": "9bfd09c2-0d06-46f6-a6d6-29688323be25",
                            "children": [],
                        },
                        {
                            "response_person": 85020200,
                            "41": {"value": [3.6], "repr": "0", "expression": None},
                            "54": {"value": ["4.76"], "repr": "0", "expression": None},
                            "52": {"value": [0], "repr": "0", "expression": "=A+B"},
                            "id": "9bfd09c2-0d06-46f6-2346-29688d83be25",
                            "children": [],
                        },
                    ],
                },
                {
                    "response_person": 85010000,
                    "41": {"value": ["20"]},
                    "54": {"value": ["10"]},
                    "52": {"value": [0], "repr": "0", "expression": "=A+B"},
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be24",
                    "children": [],
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20]},
                    "54": {"value": ["10"]},
                    "52": {"value": [0], "repr": "0", "expression": "=A+B"},
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be23",
                    "children": [],
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20]},
                    "52": {"value": [0], "repr": "0", "expression": "=A+B"},
                    "62": {"value": ["WORLD"], "repr": "WORLD"},
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be22",
                    "children": [],
                },
            ]
        }
    ]
}

T1_RIGHT_TEST_TREE_AFTER_RECALC = {
    "response_person": 10000000,
    "children": [
        {
            "response_person": 85000000,
            "children": [
                {
                    "response_person": 85020000,
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be25",
                    "children": [
                        {
                            "response_person": 85020100,
                            "41": {"value": [15], "repr": "0", "expression": None},
                            "54": {"value": ["10"], "repr": "0", "expression": None},
                            "62": {"value": ["HELLO"], "repr": "HELLO"},
                            "72": {"value": [" WORLD"], "repr": " WORLD"},
                            "id": "9bfd09c2-0d06-46f6-a6d6-29688323be25",
                            "children": [],
                            "52": {"value": [25], "repr": "25 %", "color": "#008000"},
                            "82": {
                                "value": ["HELLO WORLD"],
                                "repr": "HELLO WORLD",
                                "color": None,
                            },
                        },
                        {
                            "response_person": 85020200,
                            "41": {"value": [3.6], "repr": "0", "expression": None},
                            "54": {"value": ["4.76"], "repr": "0", "expression": None},
                            "52": {
                                "value": [8.36],
                                "repr": "8.36 %",
                                "expression": "=A+B",
                                "color": "#0000ff",
                            },
                            "id": "9bfd09c2-0d06-46f6-2346-29688d83be25",
                            "children": [],
                            "82": {"value": [""], "repr": "", "color": None},
                        },
                    ],
                    "41": {"value": [9.3], "repr": "9.30", "color": None},
                    "52": {"value": [14.06], "repr": "14.06 %", "color": "#008000"},
                    "54": {"value": [4.76], "repr": "4.76", "color": None},
                    "62": {"value": ["HELLO"], "repr": "HELLO", "color": None},
                },
                {
                    "response_person": 85010000,
                    "41": {"value": ["20"], "repr": "20", "color": None},
                    "54": {"value": ["10"], "repr": "10", "color": None},
                    "52": {
                        "value": [30],
                        "repr": "30 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be24",
                    "children": [],
                    "82": {"value": [""], "repr": "", "color": None},
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20], "repr": "20", "color": None},
                    "54": {"value": ["10"], "repr": "10", "color": None},
                    "52": {
                        "value": [30],
                        "repr": "30 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be23",
                    "children": [],
                    "82": {"value": [""], "repr": "", "color": None},
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20], "repr": "20", "color": None},
                    "52": {
                        "value": [20],
                        "repr": "20 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "62": {"value": ["WORLD"], "repr": "WORLD"},
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be22",
                    "children": [],
                    "82": {"value": ["WORLD"], "repr": "WORLD", "color": None},
                },
            ],
            "41": {"value": [17.325], "repr": "17.33", "color": None},
            "52": {"value": [22.085], "repr": "22.09 %", "color": "#008000"},
            "54": {"value": [4.76], "repr": "4.76", "color": None},
            "62": {"value": ["HELLO WORLD"], "repr": "HELLO WORLD", "color": None},
        }
    ],
    "41": {"value": [17.325], "repr": "17.33", "color": None},
    "52": {"value": [22.085], "repr": "22.09 %", "color": "#008000"},
    "54": {"value": [4.76], "repr": "4.76", "color": None},
    "62": {"value": ["HELLO WORLD"], "repr": "HELLO WORLD", "color": None},
}

T1_RIGHT_TEST_TREE_AFTER_RECALC_2 = {
    "response_person": 10000000,
    "children": [
        {
            "response_person": 85000000,
            "children": [
                {
                    "response_person": 85020000,
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be25",
                    "children": [
                        {
                            "response_person": 85020100,
                            "41": {"value": [15], "repr": "0", "expression": None},
                            "54": {"value": ["10"], "repr": "0", "expression": None},
                            "62": {"value": ["HELLO"], "repr": "HELLO"},
                            "72": {"value": [" WORLD"], "repr": " WORLD"},
                            "id": "9bfd09c2-0d06-46f6-a6d6-29688323be25",
                            "children": [],
                        },
                        {
                            "response_person": 85020200,
                            "41": {"value": [3.6], "repr": "0", "expression": None},
                            "54": {"value": ["4.76"], "repr": "0", "expression": None},
                            "52": {"value": [0], "repr": "0", "expression": "=A+B"},
                            "id": "9bfd09c2-0d06-46f6-2346-29688d83be25",
                            "children": [],
                        },
                    ],
                    "41": {"value": [9.3], "repr": "9.30", "color": None},
                    "52": {"value": [14.06], "repr": "14.06 %", "color": None},
                    "54": {"value": [4.76], "repr": "4.76", "color": None},
                    "62": {"value": ["HELLO"], "repr": "HELLO", "color": None},
                },
                {
                    "response_person": 85010000,
                    "41": {"value": ["20"], "repr": "20", "color": None},
                    "54": {"value": ["10"], "repr": "10", "color": None},
                    "52": {
                        "value": [30],
                        "repr": "30 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be24",
                    "children": [],
                    "82": {"value": [""], "repr": "", "color": None},
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20], "repr": "20", "color": None},
                    "54": {"value": ["10"], "repr": "10", "color": None},
                    "52": {
                        "value": [30],
                        "repr": "30 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be23",
                    "children": [],
                    "82": {"value": [""], "repr": "", "color": None},
                },
                {
                    "response_person": 85020000,
                    "41": {"value": [20], "repr": "20", "color": None},
                    "52": {
                        "value": [20],
                        "repr": "20 %",
                        "expression": "=A+B",
                        "color": "#008000",
                    },
                    "62": {"value": ["WORLD"], "repr": "WORLD"},
                    "id": "9bfd09c2-0d06-46f6-a6d6-29688d83be22",
                    "children": [],
                    "82": {"value": ["WORLD"], "repr": "WORLD", "color": None},
                },
            ],
            "41": {"value": [17.325], "repr": "17.33", "color": None},
            "52": {"value": [22.085], "repr": "22.09 %", "color": "#008000"},
            "54": {"value": [4.76], "repr": "4.76", "color": None},
            "62": {"value": ["HELLO WORLD"], "repr": "HELLO WORLD", "color": None},
        }
    ],
    "41": {"value": [17.325], "repr": "17.33", "color": None},
    "52": {"value": [22.085], "repr": "22.09 %", "color": "#008000"},
    "54": {"value": [4.76], "repr": "4.76", "color": None},
    "62": {"value": ["HELLO WORLD"], "repr": "HELLO WORLD", "color": None},
}

# data for test calculation row values (T2)

T2_NAME_COLUMNS = {
    10000001: "AAA",
    10000002: "AAB",
    1: "A",
    2: "B",
    3: "C",
    4: "E",
    5: "F",
    6: "G",
    7: "H",
    8: "I",
    9: "J",
    10: "K",
    11: "L",
    12: "M",
    13: "N",
    14: "O",
    15: "P",
    16: "R",
    17: "S",
    18: "T",
    19: "U",
    20: "V",
    21: "W",
    22: "X",
    23: "Y",
    24: "Z",
    25: "AA",
    26: "AB",
    27: "AC"
}

T2_TYPE_COLUMNS = {
    10000001: DATE_TYPE,
    10000002: DATETIME_TYPE,
    1: NUMBER_TYPE,
    2: NUMBER_TYPE,
    3: NUMBER_TYPE,
    4: NUMBER_TYPE,
    5: NUMBER_TYPE,
    6: NUMBER_TYPE,
    7: NUMBER_TYPE,
    8: NUMBER_TYPE,
    9: NUMBER_TYPE,
    10: DATETIME_TYPE,
    11: NUMBER_TYPE,
    12: NUMBER_TYPE,
    13: NUMBER_TYPE,
    14: BOOLEAN_TYPE,
    15: BOOLEAN_TYPE,
    16: NUMBER_TYPE,
    17: NUMBER_TYPE,
    18: NUMBER_TYPE,
    19: BOOLEAN_TYPE,
    20: NUMBER_TYPE,
    21: STRING_TYPE,
    22: STRING_TYPE,
    23: STRING_TYPE,
    24: NUMBER_TYPE,
    25: NUMBER_TYPE,
    26: STRING_TYPE,
    27: NUMBER_TYPE,
    28: TIME_TYPE,
    29: DATETIME_TYPE,
    30: DATETIME_TYPE
}

T2_FORMULA_COLUMNS = {
    3: "=E+3",
    4: "=A+4.5",
    5: "=C+E",
    6: "=C*E",
    7: "=G/E",
    8: "=sum(A;B;C;E;1)",
    9: "=count(A;B;C;E;1)",
    10: "=date(2012;2;2)",
    11: "=year(date(2012;2;2))",
    12: "=month(date(2012;2;2))",
    13: "=day(date(2012;2;2))",
    14: "=day(now())=day(today())",
    15: "=month(today())=month(now())",
    16: "=weekday(date(2012;2;2))",
    17: "=weekday(date(2012;2;2);2)",
    18: "=weekday(date(2012;2;2);1)",
    19: "=and(true;not(not(\"34\"));not(false))",
    20: "=if(or(today()<date(2012;2;2);(2>3));weekday(date(2012;2;2);2);year(date(2012;2;2)))",
    21: "=textjoin(\",\";0;\"22\";\"\";4;\"dsdss\")",
    22: "=textjoin(\",\";1;\"22\";\"\";4;\"dsdss\")",
    23: "=choose(\"2\";3;\"5\";10)",
    24: "=switch(5;32;3;2;10;228)",
    25: "=switch(\"2\";32;3;2;10;228)",
    26: "=concat(2.3;1;23;\"2.3\";3;2;\"dfdfd\")",
    27: "=day(AAA+3)",
    28: "=time(2;3;2)",
    29: "=time(2;3;2)+minute(time(2;3;2))",
    30: "=date(2022;2;2)+time(2;3;2)"
}

T2_ROW_VALUES = {
    1: [22],
    2: [12, 32],
    10000001: datetime.date(2012, 2, 2),
    10000002: datetime.datetime(2012, 2, 2, 12, 3, 33)
}

T2_RIGHT_ROW_VALUES_AFTER_CALC = {
    1: 22,
    2: 44,
    3: 29.5,
    4: 26.5,
    5: 56,
    6: 781.75,
    7: 29.5,
    8: 123,
    9: 5,
    10: datetime.datetime(2012, 2, 2, 0, 0),
    11: 2012,
    12: 2,
    13: 2,
    14: True,
    15: True,
    16: 5,
    17: 4,
    18: 5,
    19: True,
    20: 2012,
    21: "22,,4,dsdss",
    22: "22,4,dsdss",
    23: "5",
    24: 228,
    25: 10,
    26: "2.31232.332dfdfd",
    27: 5,
    28: datetime.time(2, 3, 2),
    29: datetime.datetime(1970, 1, 4, 2, 3, 2),
    30: datetime.datetime(2022, 2, 2, 2, 3, 2),
    10000001: datetime.date(2012, 2, 2),
    10000002: datetime.datetime(2012, 2, 2, 12, 3, 33)
}
