--запуск 1 сессии
BEGIN ;
--запуск 2 сессии
BEGIN ;
--проверка начальных состояний таблицы в обеих сессиях;
SELECT * FROM pizzeria;
 id |     name      | rating 
----+---------------+--------
  2 | Dominos       |    4.3
  3 | DoDo Pizza    |    3.2
  4 | Papa Johns    |    4.9
  5 | Best Pizza    |    2.3
  6 | DinoPizza     |    4.2
  1 | Pizza Hut     |    3.0
 10 | Kazan Pizza   |      5
 11 | Kazan Pizza 2 |      4

SELECT SUM(rating) FROM pizzeria;
-- изменим рейтинг для пиццерии с айди = 1 в первом окне
 UPDATE pizzeria SET rating = 4.6 WHERE id=1;
-- изменим рейтинг для пиццерии с айди = 2 во втором окне
 UPDATE pizzeria SET rating = 5 WHERE id=2;
-- пока никаких проблем не наблюдается
-- теперь изменим рейтинг для пиццерии с айди = 2 в первом окне
  UPDATE pizzeria SET rating = 4 WHERE id=2;
--возник конфликт, т.к мы уже пытаемся изменить этот параметр в другом окне
--и ожидаем завершения оперцаии оттуда
--по логике мы должны сделать коммит из второго окна, чтобы завершить там операцию
--над рейтингом пиццерии с айди = 2, но вместо этого мы попробуем изменить данные
--пиццерии, которые уже меняем в первом окне
UPDATE pizzeria SET rating = 3.6 WHERE id=1;
--получаем следующую ошибку во втором окне (ERROR:  deadlock detected)
-- после чего апдейты в первом окне завершаются успешно
--теперь делаем коммит в первом окне
COMMIT TRANSACTION;
--затем во втором
COMMIT TRANSACTION;
--ради интереса выведем результаты и заметим, что в силу вступили только изменения из 1 окна
SELECT * FROM pizzeria;

 id |     name      | rating 
----+---------------+--------
  3 | DoDo Pizza    |    3.2
  4 | Papa Johns    |    4.9
  5 | Best Pizza    |    2.3
  6 | DinoPizza     |    4.2
 10 | Kazan Pizza   |      5
 11 | Kazan Pizza 2 |      4
  1 | Pizza Hut     |    4.6
  2 | Dominos       |      4
