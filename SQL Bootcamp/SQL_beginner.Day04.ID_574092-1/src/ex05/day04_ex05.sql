CREATE VIEW v_price_with_discount AS(
WITH discount AS (
SELECT (price - price * 0.1)::int AS discount_price,id 
FROM menu
)
SELECT p.name,m.pizza_name,m.price, discount_price
FROM person_order po
JOIN menu m ON po.menu_id = m.id
JOIN person p ON po.person_id = p.id
JOIN discount d ON d.id = m.id
ORDER BY p.name, m.pizza_name)

