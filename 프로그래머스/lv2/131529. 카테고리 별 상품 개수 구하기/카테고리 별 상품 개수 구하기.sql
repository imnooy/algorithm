-- 코드를 입력하세요
SELECT substring(product_code, 1, 2) as category, count(substring(product_code, 1, 2)) as products
from product
group by category
order by category;
