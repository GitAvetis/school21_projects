SELECT name as object_name
FROM person
UNION ALL
SELECT pizza_name as object_name
FROM menu
order by object_name