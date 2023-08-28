select calculation_row_values(
               '{"41": "A","54": "B","52": "C","62": "E","72": "F"}'::jsonb,
               '{"41": 1,"54": 1,"52": 1,"62": 1,"72": 1}'::jsonb,
               '{"52": "=A+B","62": "=C+C+A","72": "=E+C"}'::jsonb,
               '{"41": 32, "54": 32}'::jsonb);

select calculation_row_values(
               '{
                 "10000001": "AAA",
                 "10000002": "AAB",
                 "1": "A",
                 "2": "B",
                 "3": "C",
                 "4": "E",
                 "5": "F",
                 "6": "G",
                 "7": "H",
                 "8": "I",
                 "9": "J",
                 "10": "K",
                 "11": "L",
                 "12": "M",
                 "13": "N",
                 "14": "O",
                 "15": "P",
                 "16": "R",
                 "17": "S",
                 "18": "T",
                 "19": "U",
                 "20": "V",
                 "21": "W",
                 "22": "X",
                 "23": "Y",
                 "24": "Z",
                 "25": "AA",
                 "26": "AB",
                 "27": "AC",
                 "28": "AD",
                 "29": "AE",
                 "30": "AF",
                 "31": "AG"
               }'::jsonb,
               '{
                 "10000001": 5,
                 "10000002": 6,
                 "1": 1,
                 "2": 1,
                 "3": 1,
                 "4": 1,
                 "5": 1,
                 "6": 1,
                 "7": 1,
                 "8": 1,
                 "9": 1,
                 "10": 2,
                 "11": 1,
                 "12": 1,
                 "13": 1,
                 "14": 6,
                 "15": 6,
                 "16": 1,
                 "17": 1,
                 "18": 1,
                 "19": 3,
                 "20": 1,
                 "21": 2,
                 "22": 2,
                 "23": 2,
                 "24": 1,
                 "25": 1,
                 "26": 2,
                 "27": 1,
                 "28": 2,
                 "29": 6,
                 "30": 2,
                 "31": 1
               }'::jsonb,
               '{
                 "3": "=E+3",
                 "4": "=A+4",
                 "5": "=C+E",
                 "6": "=C*E",
                 "7": "=G/E",
                 "8": "=sum(A;B;C;E;1)",
                 "9": "=count(A;B;C;E;1)",
                 "10": "=textjoin(\".\";1;day(date(2012;2;2));month(date(2012;2;2));year(date(2012;2;2)))",
                 "11": "=year(date(2012;2;2))",
                 "12": "=month(date(2012;2;2))",
                 "13": "=day(date(2012;2;2))",
                 "14": "=(now()-now())+1",
                 "15": "=today()*0+1",
                 "16": "=weekday(date(2012;2;2))",
                 "17": "=weekday(date(2012;2;2);2)",
                 "18": "=weekday(date(2012;2;2);1)",
                 "19": "=and(true;not(not(\"34\"));not(false))",
                 "20": "=if(or(today()<date(2012;2;2);(2>3));weekday(date(2012;2;2);2);year(date(2012;2;2)))",
                 "21": "=textjoin(\",\";0;\"22\";\"\";4;\"dsdss\")",
                 "22": "=textjoin(\",\";1;\"22\";\"\";4;\"dsdss\")",
                 "23": "=choose(\"2\";3;\"5\";10)",
                 "24": "=switch(5;32;3;2;10;228)",
                 "25": "=switch(\"2\";32;3;2;10;228)",
                 "26": "=concat(2.3;1;23;\"2.3\";3;2;\"dfdfd\")",
                 "27": "=day(AAA+3)",
                 "28": "=textjoin(\":\";1;hour(time(1;3;2));minute(time(1;3;2));second(time(1;3;2)))",
                 "29": "=hour(time(1;3;2))+minute(time(1;3;2))",
                 "30": "=concat(textjoin(\".\";1;day(date(2022;2;2)+time(2;3;2));month(date(2022;2;2)+time(2;3;2));year(date(2022;2;2)+time(2;3;2)));\" \";textjoin(\":\";1;hour(date(2022;2;2)+time(2;3;2));minute(date(2022;2;2)+time(2;3;2));second(date(2022;2;2)+time(2;3;2))))",
                 "31": "=if(0;2;)"
               }'::jsonb,
               '{
                 "1": 22,
                 "2": 44,
                 "10000001": 1328126400,
                 "10000002": 1328169813
               }'::jsonb
           );