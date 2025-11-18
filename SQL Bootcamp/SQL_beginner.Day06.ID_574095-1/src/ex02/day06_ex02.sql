SELECT 
	p.name,
	m.pizza_name,
	m.price,
	(m.price * ((100 - pd.discount) / 100))::integer  AS discount_price,
	pz.name AS pizzeria_name
FROM 
	person_order AS po
	JOIN person AS p ON p.id = po.person_id
	JOIN menu AS m ON m.id = po.menu_id
	JOIN person_discounts AS pd ON p.id = pd.person_id AND m.pizzeria_id = pd.pizzeria_id
	JOIN pizzeria AS pz ON m.pizzeria_id = pz.id
ORDER BY p.name,m.pizza_name