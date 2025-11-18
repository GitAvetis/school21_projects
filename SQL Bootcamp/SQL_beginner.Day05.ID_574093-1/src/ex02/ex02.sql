CREATE INDEX IF NOT EXISTS idx_person_name ON person (UPPER(name));

SET enable_seqscan TO OFF;

EXPLAIN ANALYZE
SELECT * 
FROM person 
WHERE age >20
AND UPPER(name) = 'ELVIRA'