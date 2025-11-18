COMMENT ON TABLE person_discounts IS 'personal discounts for people';
COMMENT ON COLUMN person_discounts.id IS 'primary key for the person_discounts table';
COMMENT ON COLUMN person_discounts.person_id IS 'aggregated state from person_id column';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'aggregated state from pizzeria_id column';
COMMENT ON COLUMN person_discounts.discount IS 'Calculated personal discount value by the next pseudo code: if “amount of orders” = 1 then “discount” = 10.5  else if “amount of orders” = 2 then  “discount” = 22 else  “discount” = 30';



	


	