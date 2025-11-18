DROP TRIGGER IF EXISTS trg_person_insert_audit ON person_audit;
DROP TRIGGER IF EXISTS trg_person_update_audit ON person_audit;
DROP TRIGGER IF EXISTS trg_person_delete_audit ON person_audit;

DROP FUNCTION  IF EXISTS fnc_trg_person_insert_audit;
DROP FUNCTION  IF EXISTS fnc_trg_person_update_audit;
DROP FUNCTION  IF EXISTS fnc_trg_person_delete_audit;



CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS TRIGGER
AS $fnc_tag_person_audit$ 
BEGIN
	INSERT INTO person_audit(type_event,row_id,name,age,gender,address)
	VALUES ('D',OLD.id,OLD.name,OLD.age,OLD.gender,OLD.address); 
	RETURN NULL;
END;
$fnc_tag_person_audit$  LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER fnc_trg_person_audit
	AFTER DELETE ON person
	FOR EACH ROW 
	EXECUTE FUNCTION fnc_trg_person_delete_audit();
DELETE FROM person WHERE id = 10;
SELECT * FROM person_audit;