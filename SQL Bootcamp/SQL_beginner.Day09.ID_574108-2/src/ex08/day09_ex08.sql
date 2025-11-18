CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop int DEFAULT 10)
RETURNS TABLE (fib_num int)
		AS $$
		WITH RECURSIVE fib (f1,f2) AS(
		VALUES (0, 1)--стартовая часть
		UNION
		SELECT--рекурсивная часть
			f2,--вместо нового f1 запишем старый f2
			f1 +f2--как f2 запишем сумму f1 и f2
		FROM fib--когда дошли до пары 89 144 мы не проходим условие для продолжения
		WHERE f2 < pstop)--последняя пара это 55 89 причём 89 записан как f1
		SELECT f1  FROM fib --поэтому возвращаем в fib_num значение f1
$$ LANGUAGE SQL;
--select * from fnc_fibonacci(100);
--select * from fnc_fibonacci();






