WITH cheese AS(
		SELECT person.name AS name
		FROM menu
			JOIN person_order ON menu.id = person_order.menu_id
			JOIN person ON person.id = person_order.person_id
		WHERE menu.pizza_name='cheese pizza'
			AND person.gender = 'female'),
	pepperoni AS(
		SELECT person.name AS name
		FROM menu
			JOIN person_order ON menu.id = person_order.menu_id
			JOIN person ON person.id = person_order.person_id
		WHERE menu.pizza_name='pepperoni pizza'
			AND person.gender = 'female')
SELECT cheese.name AS name
FROM cheese
INNER JOIN pepperoni ON cheese.name = pepperoni.name
ORDER BY name