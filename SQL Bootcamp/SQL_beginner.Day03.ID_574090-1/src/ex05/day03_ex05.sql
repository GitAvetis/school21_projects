SELECT  pizzeria.name
FROM pizzeria
JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
JOIN person ON person.id = person_visits.person_id
WHERE person.name = 'Andrey'
AND NOT EXISTS (
	SELECT 1
	FROM menu
	JOIN person_order ON menu.id = person_order.menu_id
	WHERE  pizzeria.id = menu.pizzeria_id
	AND person.id = person_order.person_id
)