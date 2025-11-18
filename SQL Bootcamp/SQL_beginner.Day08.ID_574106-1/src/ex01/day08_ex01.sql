--проверяем обе сессии(read committed)
SHOW TRANSACTION ISOLATION LEVEL;
--запуск 1 сессии
BEGIN TRANSACTION;
--запуск 2 сессии
BEGIN TRANSACTION;
--проверка вывода(в обеих сессиях должен быть рейтинг 5)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--обновление рейтинга 1
UPDATE pizzeria
SET rating = 4
WHERE name = 'Pizza Hut';
--обновление рейтинга 2(не проходит)
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';
--делаем коммит 1(после этого во 2 сессии завершается апдейт)
COMMIT TRANSACTION;
--делаем коммит 2
COMMIT TRANSACTION;
--проверка вывода в обоих окнах
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--в обоих окнах получается одинаковый результат 3.6 (то, что мы коммитили из второго окна)