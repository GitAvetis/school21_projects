SELECT 
	COALESCE(u.name, 'not defined') AS name,
	COALESCE(u.lastname, 'not defined') AS lastname,
	curr.name AS currency_name,
	balance.money * COALESCE ((
		SELECT currency.rate_to_usd
        FROM currency
        WHERE currency.id = balance.currency_id
			AND currency.updated <= balance.updated
		ORDER BY currency.updated DESC
        LIMIT 1),
		(SELECT currency.rate_to_usd
        FROM currency
        WHERE currency.id = balance.currency_id
			AND currency.updated > balance.updated
		ORDER BY currency.updated 
        LIMIT 1
		)) AS currency_in_usd
FROM 
	balance 
FULL JOIN 
	"user" AS u ON balance.user_id = u.id
JOIN (
	SELECT DISTINCT 
		cur.name,
		cur.id
	FROM 
		currency AS cur) AS curr ON curr.id = balance.currency_id
ORDER BY 
	1 DESC, 2,3
	
	
	
	
	
		