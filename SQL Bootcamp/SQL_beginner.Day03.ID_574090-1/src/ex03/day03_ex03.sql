WITH counter AS (
	SELECT	
		pizzeria.name,SUM (
		CASE WHEN person.gender = 'male'
		THEN 1
		ELSE 0
		END
		) AS male_orders,
		SUM (
		CASE WHEN person.gender = 'female'
		THEN 1
		ELSE 0
		END) AS female_orders
	FROM pizzeria
	JOIN person_visits ON person_visits.pizzeria_id =pizzeria.id
	JOIN person ON person.id = person_visits.person_id
	GROUP BY pizzeria.name
)
SELECT 
	counter.name AS pizzeria_name
FROM 
	counter
WHERE 
	counter.male_orders != counter.female_orders
ORDER BY 
	counter.name
