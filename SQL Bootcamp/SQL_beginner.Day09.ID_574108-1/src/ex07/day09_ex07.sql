CREATE OR REPLACE FUNCTION func_minimum( 
 VARIADIC arr NUMERIC[]	)--Тип массив, затем его имя, затем тип хранящихся данных в массиве
RETURNS NUMERIC
 	  AS $$
 	SELECT min($1[g.i]) FROM generate_subscripts($1, 1) g(i);--generate_subscripts формуирем последовательность индексов массива
$$ LANGUAGE SQL;--g - временно созданная таблица для хранения индексов

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);

-- select * from fnc_person_visits_and_eats_on_date(pprice := 800);
--select * from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');




