WITH first_pz AS 
(SELECT  m.pizza_name AS pizza_name,pz.name, price
FROM pizzeria pz
JOIN menu m ON pz.id = m.pizzeria_id),
second_pz AS (SELECT  pz.name, m.pizza_name,price
FROM pizzeria pz
JOIN menu m ON pz.id = m.pizzeria_id)

SELECT  DISTINCT
	first_pz.pizza_name, 
	first_pz.name AS pizzeria_name_1,
	second_pz.name AS pizzeria_name_2,
	first_pz.price
FROM first_pz,second_pz
WHERE first_pz.price = second_pz.price AND
	first_pz.pizza_name = second_pz.pizza_name
AND first_pz.name < second_pz.name
ORDER BY first_pz.pizza_name
