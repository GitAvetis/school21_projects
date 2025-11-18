CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date( 
	pperson varchar DEFAULT 'Dmitriy',
	pprice integer DEFAULT 500,
	pdate date DEFAULT '2022-01-08')
RETURNS TABLE(
 	pizzeria_name varchar
) AS $$
 	SELECT pz.name 
	 FROM pizzeria AS pz
	 JOIN person_visits AS pv ON pz.id = pv.pizzeria_id
	 JOIN person AS p ON pv.person_id = p.id
	 JOIN menu AS m ON pz.id = m.pizzeria_id
	WHERE pperson = p.name AND pprice > m.price AND pdate = pv.visit_date
$$ LANGUAGE SQL;

-- select * from fnc_person_visits_and_eats_on_date(pprice := 800);
--select * from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');




