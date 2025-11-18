WITH counter_of_visits AS (
	SELECT 
		person_id,
		COUNT(person_id) AS count_of_visits
	FROM 
		person_visits
	GROUP BY person_id	  	
)  
SELECT *
FROM counter_of_visits
ORDER BY count_of_visits DESC, person_id ASC

	


