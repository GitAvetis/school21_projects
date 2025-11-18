SELECT  COALESCE (person.name,'-') AS person_name,
		pv.visit_date AS visit_date,
		COALESCE ( pizzeria.name,'-') AS pizzeria_name
FROM(SELECT person_id,pizzeria_id,visit_date
	FROM person_visits
	WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS pv
	FULL JOIN pizzeria ON pizzeria.id = pv.pizzeria_id
	FULL JOIN person ON person.id = pv.person_id
ORDER BY person_name, visit_date,pizzeria_name