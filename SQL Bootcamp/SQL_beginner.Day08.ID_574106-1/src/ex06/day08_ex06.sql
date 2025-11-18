--запуск 1 сессии
BEGIN ISOLATION LEVEL REPEATABLE READ;
--запуск 2 сессии
BEGIN ISOLATION LEVEL REPEATABLE READ;
--проверка суммы в первой сессии (26.9)
SELECT SUM(rating) FROM pizzeria;
--добавим ещё одну пиццерию в сессии 2
INSERT INTO pizzeria (id,name,rating) VALUES (11,'Kazan Pizza 2',4);
--делаем коммит во 2
COMMIT TRANSACTION;
--проверка суммы в первой сессии (26.9 изменений из 2 сесии пока нет)
SELECT SUM(rating) FROM pizzeria;
--делаем коммит в 1
COMMIT TRANSACTION;
--проверка суммы в первой сессии после коммита  
--(теперь изменения из 2-ой сессии подтянулись сумма = 30.9)
SELECT SUM(rating) FROM pizzeria;
--проверка суммы во второй сессии после (те же 30.9)
SELECT SUM(rating) FROM pizzeria;