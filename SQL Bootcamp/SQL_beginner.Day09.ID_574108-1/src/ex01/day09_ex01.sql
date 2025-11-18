 --CREATE OR REPLACE для избежания повторения существующей функции
CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit() RETURNS TRIGGER--тип возвращаемого значения
AS $fnc_tag_person_audit$ -- можно писать просто $$ без названий
BEGIN
	INSERT INTO person_audit(type_event,row_id,name,age,gender,address)--(столб created заполится дефолтным значением)
	VALUES ('U',OLD.id,OLD.name,OLD.age,OLD.gender,OLD.address);--заменили  new на old чтобы сохранить в таблицу person_audit старые значения 
	RETURN NULL;--для  афтер тригеров можно возвращать NULL
END;
$fnc_tag_person_audit$  LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_update_audit--триггер срабатывает после того как к таблице 
	AFTER UPDATE ON person--person применили UPDATE
	FOR EACH ROW --и для каждой строки функции вызывается заново
	EXECUTE FUNCTION fnc_trg_person_update_audit();--можно вместо PROCEDURE писать FUNCTION
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
SELECT * FROM person_audit;

		 
		

 