WITH 
	orders AS (SELECT
					pz.name AS name,
					COUNT(po) AS count,
					'order' AS action_type
				FROM 
					person_order po
				JOIN 
					menu AS m ON po.menu_id = m.id
				JOIN
					pizzeria AS pz ON pz.id = m.pizzeria_id
				GROUP BY pz.name), 
	visits AS (SELECT 
					pz.name AS name,
					COUNT(pv) AS count,
					'visit' AS action_type
				FROM 
					person_visits pv
				JOIN 
					pizzeria AS pz ON pz.id = pv.pizzeria_id
				GROUP BY pz.name)
SELECT 
	pz.name,
	COALESCE(od.count,0)+COALESCE(vs.count,0) AS total_count
FROM
	pizzeria AS pz
JOIN
	orders AS od ON od.name = pz.name
JOIN 
	visits AS vs ON vs.name = pz.name
ORDER BY total_count DESC, name



	


