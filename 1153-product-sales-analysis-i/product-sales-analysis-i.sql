# Write your MySQL query statement below
SELECT s.year , s.price , p.product_name
from Sales s
LEFT JOIN Product p
on p.product_id = s.product_id;