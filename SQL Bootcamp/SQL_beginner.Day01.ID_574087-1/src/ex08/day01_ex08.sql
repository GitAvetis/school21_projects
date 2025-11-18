SELECT order_date,
	CONCAT(p.name,' (age:',p.age,')') AS person_information
FROM person_order
	NATURAL JOIN (
	SELECT id AS person_id,
	person.name,person.age
		FROM person
	) AS p
ORDER BY order_date,
    person_information
	
