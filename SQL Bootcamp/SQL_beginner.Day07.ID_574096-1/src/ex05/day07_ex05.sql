WITH orders_count AS (
	SELECT 
		person_id,
		COUNT(person_id) AS counter
	FROM 
		person_order
	GROUP BY person_id
)
SELECT 
	p.name
FROM person AS p
JOIN orders_count AS oc ON oc.person_id = p.id
WHERE counter > 0
ORDER BY name

	


	


