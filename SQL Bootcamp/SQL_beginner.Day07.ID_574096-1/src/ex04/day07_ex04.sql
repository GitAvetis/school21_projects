WITH visits_count AS (
	SELECT 
		person_id,
		COUNT(person_id) AS counter
	FROM 
		person_visits
	GROUP BY person_id
)
SELECT 
	p.name,
	vc.counter AS count_of_visits
FROM person AS p
JOIN visits_count AS vc ON vc.person_id = p.id
WHERE vc.counter > 3
	


	


