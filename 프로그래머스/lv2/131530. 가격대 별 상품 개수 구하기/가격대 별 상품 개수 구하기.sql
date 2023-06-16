-- 코드를 입력하세요
SELECT (floor(price/10000))*10000 as price_group, count((price%10000)*10000) as products
from product
group by price_group
order by price_group;

# select floor(price) from product
# order by price;