CREATE UNIQUE INDEX IF NOT EXISTS idx_menu_unique 
ON menu (pizzeria_id,pizza_name);
SET enable_seqscan TO OFF;
EXPLAIN ANALYZE
SELECT *
FROM menu
WHERE pizzeria_id BETWEEN 0 AND 15;
