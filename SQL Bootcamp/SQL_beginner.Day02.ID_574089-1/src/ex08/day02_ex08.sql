SELECT person.name AS name
FROM menu
	JOIN person_order ON menu.id = person_order.menu_id
	JOIN person ON person.id = person_order.person_id
WHERE person.address IN ('Moscow','Samara') AND 
	menu.pizza_name IN ('pepperoni pizza','mushroom pizza')
	AND person.gender = 'male'
ORDER BY name DESC