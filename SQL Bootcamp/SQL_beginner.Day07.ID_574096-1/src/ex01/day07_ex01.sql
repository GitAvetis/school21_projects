SELECT 
	p.name AS name,
	COUNT(person_id) AS count_of_visits
FROM 
	person_visits
JOIN 
	person AS p ON p.id = person_visits.person_id
GROUP BY p.name	  	
ORDER BY count_of_visits DESC, name ASC
LIMIT 4 ;



	


