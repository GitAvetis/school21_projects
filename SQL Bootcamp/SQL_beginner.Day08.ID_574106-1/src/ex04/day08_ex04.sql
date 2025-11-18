--запуск 1 сессии
BEGIN ISOLATION LEVEL SERIALIZABLE;
--запуск 2 сессии
BEGIN ISOLATION LEVEL SERIALIZABLE;
--проверяем обе сессии(SERIALIZABLE)
SHOW TRANSACTION ISOLATION LEVEL;
--проверка вывода в первой сесии (рейтинг = 3.6)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--обновление рейтинга 2
UPDATE pizzeria
SET rating = 3.0
WHERE name = 'Pizza Hut';
--делаем коммит 2
COMMIT TRANSACTION;
--проверка вывода в первой сесии (рейтинг = 3.6, пока изменения не подтянулись)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--делаем коммит 1
COMMIT TRANSACTION;
--проверка вывода в первой сесии (рейтинг = 3.0 теперь мы видим результат апдейта второй сессии)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--проверка вывода в обоих окнах
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';
--в обоих окнах получается одинаковый результат 3.0 (то, что мы коммитили из второго окна)