(SELECT 
	pz.name AS name,
	COUNT(po) AS count,
	'order' AS action_type
FROM 
	person_order po
JOIN 
	menu AS m ON po.menu_id = m.id
JOIN
	pizzeria AS pz ON pz.id = m.pizzeria_id
GROUP BY pz.name
LIMIT 3)

UNION

(SELECT 
	pz.name AS name,
	COUNT(pv) AS count,
	'visit' AS action_type
FROM 
	person_visits pv
JOIN 
	pizzeria AS pz ON pz.id = pv.pizzeria_id
GROUP BY pz.name
LIMIT 3)
ORDER BY action_type, count DESC



	


