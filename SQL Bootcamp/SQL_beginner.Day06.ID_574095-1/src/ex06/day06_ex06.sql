CREATE SEQUENCE IF NOT EXISTS seq_person_discounts
AS bigint
START 1 
OWNED BY person_discounts.id;
--создал последовательность начинающуюся с 1 для столбца id
SELECT SETVAL('seq_person_discounts', COALESCE(MAX(id), 0) + 1) 
FROM person_discounts;
--установил правильное значение
ALTER TABLE person_discounts
ALTER COLUMN id
SET DEFAULT NEXTVAL('seq_person_discounts');
--записал следующее значение в таблицу. 
--NEXTVAL сначала запишет актуальное значениеs eq_person_discounts 
--а потом только увеличится на 1
--DROP SEQUENCE IF EXISTS seq_person_discounts CASCADE;
