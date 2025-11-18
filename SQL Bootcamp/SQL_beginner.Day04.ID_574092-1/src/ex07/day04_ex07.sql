INSERT INTO person_visits(id, person_id, pizzeria_id, visit_date)
VALUES(
	(SELECT max(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Dmitriy'),
	(SELECT MAX(pizzeria_id) FROM menu WHERE price < 800
	AND pizzeria_id != (SELECT id FROM pizzeria WHERE name = 'Papa Johns')),
	'2022-01-08'

)
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;	

-- INSERT INTO person_order(id, person_id, menu_id, order_date)
-- VALUES(
-- 	(SELECT max(id) + 1 FROM person_order),
-- 	(SELECT id FROM person WHERE name = 'Dmitriy'),
-- 	(SELECT id FROM menu WHERE pizzeria_id = 
-- 		(SELECT MAX(pizzeria_id) FROM menu WHERE price < 800
-- 		AND pizzeria_id != (SELECT id FROM pizzeria WHERE name = 'Papa Johns'))
-- 		AND pizza_name =  'cheese pizza'),
-- 	'2022-01-08'
-- )

	


