(SELECT	
	pizzeria.name
FROM 
	pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
JOIN person ON person.id = person_order.person_id
	WHERE person.gender = 'male'
EXCEPT

SELECT	
	pizzeria.name
FROM 
	pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
JOIN person ON person.id = person_order.person_id
	WHERE person.gender = 'female')
UNION
(SELECT	
	pizzeria.name
FROM 
	pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
JOIN person ON person.id = person_order.person_id
	WHERE person.gender = 'female'
EXCEPT

SELECT	
	pizzeria.name
FROM 
	pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
JOIN person ON person.id = person_order.person_id
	WHERE person.gender = 'male')



	