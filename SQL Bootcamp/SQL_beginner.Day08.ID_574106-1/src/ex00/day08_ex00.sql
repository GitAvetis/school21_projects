--ROLLBACK;
--запуск первой сессии
BEGIN TRANSACTION;
--обновление рейтинга
UPDATE pizzeria
SET rating = 5
WHERE name = 'Pizza Hut';
--проверка вывода(изменения приняты в этой сессии)
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut'
--после проверки запускаем второе окно
--повторяем тот же запрос и видим, что изменений пока нет
--делаем коммит
COMMIT TRANSACTION;
--ещё раз смотрим во втором окне, изменения появились