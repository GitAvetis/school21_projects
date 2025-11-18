SELECT id as object_id, name as object_name
FROM person
UNION
SELECT id as object_id, pizza_name as object_name
FROM menu
order by object_id,object_name