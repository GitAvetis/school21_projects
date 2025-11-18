--запуск 1 сессии
BEGIN TRANSACTION;
--запуск 2 сессии
BEGIN TRANSACTION;
--проверяем обе сессии(read committed)
SHOW TRANSACTION ISOLATION LEVEL;
--проверка вывода в первой сесии (рейтинг = 4)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--обновление рейтинга 2
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';
--делаем коммит 2
COMMIT TRANSACTION;
--проверка вывода в первой сесии (рейтинг = 3.6)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--делаем коммит 1
COMMIT TRANSACTION;
--проверка вывода в обоих окнах
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--в обоих окнах получается одинаковый результат 3.6 (то, что мы коммитили из второго окна)