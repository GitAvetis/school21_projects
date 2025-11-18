--проверяем обе сессии(REPEATABLE READ)
SHOW TRANSACTION ISOLATION LEVEL;
--запуск 1 сессии
begin isolation level repeatable read;
--запуск 2 сессии
begin isolation level repeatable read;
--проверка вывода(в обеих сессиях должен быть рейтинг 5)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--обновление рейтинга 1
UPDATE pizzeria
SET rating = 4
WHERE name = 'Pizza Hut';
--обновление рейтинга 2(не проходит)
--ERROR:  could not serialize access due to concurrent update
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';
--делаем коммит 1
COMMIT TRANSACTION;
--делаем коммит 2(ROLLBACK)
COMMIT TRANSACTION;
--проверка вывода в обоих окнах
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--теперь результат изменился(то, что мы коммитили из первого окна)
--в обоих окнах получается 4 