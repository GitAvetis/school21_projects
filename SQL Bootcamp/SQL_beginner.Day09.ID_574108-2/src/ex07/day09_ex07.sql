CREATE OR REPLACE FUNCTION func_minimum( 
 VARIADIC arr NUMERIC[]	)--Тип массив, затем его имя, затем тип хранящихся данных в массиве
RETURNS NUMERIC
 	  AS $$--$1 - первый аргумент функции
 	SELECT min($1[g.i]) FROM generate_subscripts($1, 1) g(i);--generate_subscripts формуирем последовательность индексов массива
$$ LANGUAGE SQL;--g - временно созданная таблица для хранения индексов

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);






