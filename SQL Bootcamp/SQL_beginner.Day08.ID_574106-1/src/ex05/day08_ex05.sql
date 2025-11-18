--запуск 1 сессии
BEGIN;
--запуск 2 сессии
BEGIN;
--проверяем обе сессии(read commited)
SHOW TRANSACTION ISOLATION LEVEL;
--проверка суммы в первой сессии (21.9)
SELECT SUM(rating) FROM pizzeria;
--добавим ещё одну пиццерию в сессии 2
INSERT INTO pizzeria (id,name,rating) VALUES (10,'Kazan Pizza',5);
--делаем коммит 2
COMMIT TRANSACTION;
--проверка суммы в первой сессии (26.9 видим изменения из 2 сесии)
SELECT SUM(rating) FROM pizzeria;
--делаем коммит 1
COMMIT TRANSACTION;
--проверка суммы в первой сессии после коммита  (26.9)
SELECT SUM(rating) FROM pizzeria;
--проверка суммы во второй сессии после (те же 26.9)
SELECT SUM(rating) FROM pizzeria;