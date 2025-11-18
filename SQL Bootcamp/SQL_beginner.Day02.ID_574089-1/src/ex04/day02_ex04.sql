SELECT mn.pizza_name as pizza_name,
	   pizzeria.name as pizzeria_name,
	   mn.price as price
FROM (SELECT pizza_name,price,pizzeria_id
		FROM menu
		WHERE pizza_name in('pepperoni pizza','mushroom pizza' )) AS mn
JOIN pizzeria ON pizzeria.id = mn.pizzeria_id
ORDER BY pizza_name,pizzeria_name