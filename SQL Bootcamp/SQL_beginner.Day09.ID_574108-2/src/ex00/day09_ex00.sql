CREATE TABLE IF NOT EXISTS person_audit
( created timestamp with time zone NOT NULL DEFAULT CURRENT_TIMESTAMP,
  type_event char(1) NOT NULL DEFAULT 'I' CONSTRAINT ch_type_event CHECK (type_event IN ('I','D','U')),
  row_id bigint NOT NULL,
  name varchar,
  age integer,
  gender varchar,
  address varchar
 );
 --CREATE OR REPLACE для избежания повторения существующей функции
 CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS TRIGGER--тип возвращаемого значения
 AS $fnc_tag_person_audit$ -- можно писать просто $$ без названий
 BEGIN
	INSERT INTO person_audit(type_event,row_id,name,age,gender,address)--(столб created заполится дефолтным значением)
	VALUES ('I',NEW.id,NEW.name,NEW.age,NEW.gender,NEW.address);
	RETURN NULL;--для  афтер тригеров можно возвращать NULL
END;
$fnc_tag_person_audit$  LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_insert_audit--триггер срабатывает после того как к таблице 
	AFTER INSERT ON person--person применили INSERT
	FOR EACH ROW --и для каждой строки функции вызывается заново
	EXECUTE PROCEDURE fnc_trg_person_insert_audit();--можно вместо PROCEDURE писать FUNCTION
	
--DELETE FROM person WHERE id=10;
--DELETE FROM person_audit;
INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
SELECT * FROM person_audit;

		 
		

 