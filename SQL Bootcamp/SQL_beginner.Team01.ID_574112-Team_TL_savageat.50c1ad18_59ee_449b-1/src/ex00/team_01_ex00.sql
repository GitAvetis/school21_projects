WITH cte_last_rate_to_usd AS (
	SELECT 
		curr.id,
		curr.name,(
		SELECT COALESCE (rate_to_usd, 1) AS last_rate
		FROM currency 
		WHERE updated = (SELECT max(updated) FROM currency)
		AND id = B.currency_id
		) AS last_rate_to_usd
	FROM currency AS curr 
	JOIN balance B ON B.currency_id=curr.id
    GROUP BY curr.id, 
            curr.name,B.currency_id
)
SELECT 
	COALESCE (u.name,'not defined') AS name,
	COALESCE (u.lastname,'not defined') AS lastname,
	type,
	SUM(COALESCE(b.money, 0)) AS volume,
	COALESCE (cte_last_rate_to_usd.name,'not defined') AS currency_name,
	COALESCE (last_rate_to_usd, 1) AS last_rate_to_usd,
	SUM(COALESCE(b.money, 0)) * COALESCE(last_rate_to_usd, 1) AS total_volume_in_usd 
FROM 
	"user" AS u
	FULL JOIN balance AS b ON u.id = b.user_id
	FULL JOIN cte_last_rate_to_usd  ON cte_last_rate_to_usd.id = b.currency_id
GROUP BY type, u.id,currency_id, currency_name,last_rate_to_usd
ORDER BY name DESC, lastname, type






	
	
	
