WITH RECURSIVE all_paths AS(
	SELECT 
		point1 AS tour, 
		point1,
		point2,
		cost
	FROM 
		routes
	WHERE 
		point1 = 'a'
	
	UNION ALL
	
	SELECT 
		parrent.tour || ',' || child.point1 AS path, 
		child.point1,
		child.point2,
		parrent.cost + child.cost 
	FROM 
		routes AS child
		INNER JOIN all_paths AS parrent ON child.point1 = parrent.point2
	WHERE tour NOT LIKE '%' || child.point1 || '%'
)

SELECT 
    cost AS total_cost,
    ('{' || tour || ',' || point2 || '}') AS tour
FROM all_paths 
WHERE LENGTH(tour) = 7 AND point2 = 'a'
GROUP BY tour, point2, cost
HAVING cost = (SELECT MIN(cost) FROM all_paths WHERE LENGTH(tour) = 7 AND point2 = 'a')
UNION
SELECT 
    cost AS total_cost,
    ('{' || tour || ',' || point2 || '}') AS tour
FROM all_paths 
WHERE LENGTH(tour) = 7 AND point2 = 'a'
GROUP BY tour, point2, cost
HAVING cost = (SELECT MAX(cost) FROM all_paths WHERE LENGTH(tour) = 7 AND point2 = 'a')
order by total_cost, tour;