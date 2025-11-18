DO $$
BEGIN
    DROP TABLE IF EXISTS routes;
    CREATE TABLE routes (
        point1 VARCHAR NOT NULL, 
        point2 VARCHAR NOT NULL,
        cost INT NOT NULL  
    );

    INSERT INTO routes (point1, point2, cost)
    VALUES 
        ('a', 'b', 10),
        ('b', 'a', 10),
        ('a', 'd', 20),
        ('d', 'a', 20),
        ('a', 'c', 15),
        ('c', 'a', 15),
        ('b', 'd', 25),
        ('d', 'b', 25),
        ('b', 'c', 35),
        ('c', 'b', 35),
        ('c', 'd', 30),
        ('d', 'c', 30);
END $$;

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
order by total_cost, tour;