DROP TRIGGER IF EXISTS trg_person_insert_audit ON person_audit;
DROP TRIGGER IF EXISTS trg_person_update_audit ON person_audit;
DROP TRIGGER IF EXISTS trg_person_delete_audit ON person_audit;

DROP FUNCTION  IF EXISTS fnc_trg_person_insert_audit CASCADE;
DROP FUNCTION  IF EXISTS fnc_trg_person_update_audit CASCADE;
DROP FUNCTION  IF EXISTS fnc_trg_person_delete_audit CASCADE;

DROP TRIGGER IF EXISTS trg_person_audit ON person_audit;
DROP FUNCTION  IF EXISTS fnc_trg_person_audit CASCADE;

CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS TRIGGER
AS $fnc_tag_person_audit$ 
BEGIN
	IF (TG_OP = 'DELETE') THEN
		INSERT INTO person_audit(type_event,row_id,name,age,gender,address)
		VALUES ('D',OLD.id,OLD.name,OLD.age,OLD.gender,OLD.address);
	ELSIF (TG_OP = 'INSERT') THEN
		INSERT INTO person_audit(type_event,row_id,name,age,gender,address)
		VALUES ('I',NEW.id,NEW.name,NEW.age,NEW.gender,NEW.address);
	ELSIF (TG_OP = 'UPDATE') THEN
		INSERT INTO person_audit(type_event,row_id,name,age,gender,address)
		VALUES ('U',OLD.id,OLD.name,OLD.age,OLD.gender,OLD.address);
	END IF;
	RETURN NULL;
END;
$fnc_tag_person_audit$  LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_audit
	AFTER DELETE OR INSERT OR UPDATE ON person
	FOR EACH ROW 
	EXECUTE FUNCTION fnc_trg_person_audit();
	
--DELETE FROM person_audit;
INSERT INTO person(id, name, age, gender, address)  VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;
SELECT * FROM person_audit;