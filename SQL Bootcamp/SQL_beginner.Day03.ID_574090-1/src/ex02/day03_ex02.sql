SELECT 
    menu.pizza_name,
    menu.price,
    pizzeria.name AS pizzeria_name
FROM 
    menu 
JOIN 
    pizzeria  ON pizzeria.id = menu.pizzeria_id
LEFT JOIN 
    person_order ON person_order.menu_id = menu.id
WHERE 
    person_order.id IS NULL 
ORDER BY 
    menu.pizza_name, menu.price;






	