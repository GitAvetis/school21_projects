UPDATE menu SET price = ((
SELECT price
FROM menu
WHERE pizza_name = 'greek pizza')
* 0.9)::int
WHERE pizza_name = 'greek pizza' 