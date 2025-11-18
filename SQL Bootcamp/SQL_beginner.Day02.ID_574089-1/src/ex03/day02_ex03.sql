WITH period AS(SELECT generate_series('2022-01-01'::date,'2022-01-10'::date,'1 day')::date AS missing_dates),
	visits AS(SELECT visit_date 
			FROM person_visits
			WHERE person_id = 1 OR
			person_id = 2)
SELECT missing_dates
FROM period LEFT JOIN visits ON period.missing_dates = visits.visit_date
WHERE visit_date IS NULL
ORDER BY visit_date ASC

