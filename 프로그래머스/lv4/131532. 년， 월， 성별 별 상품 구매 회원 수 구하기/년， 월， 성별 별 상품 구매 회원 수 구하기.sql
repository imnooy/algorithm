-- 코드를 입력하세요
# select o.online_sale_id, o.sales_date, u.gender
# from online_sale o, user_info u
# where o.user_id=u.user_id
# order by o.sales_date, u.gender;

# 112 - 62 = 51?

# select * from online_sale
# order by sales_date;

# 세일 테이블에서.. 2월 53명 중.. 0이 29 null인게 2명
SELECT date_format(o.sales_date, '%Y') as YEAR, date_format(o.sales_date, '%m')%100 as MONTH, u.gender as GENDER, count(distinct o.user_id) as users
from user_info u, online_sale o
where u.user_id=o.user_id and u.gender is not null 
group by date_format('%Y', o.sales_date), date_format(o.sales_date, '%m'), u.gender
order by date_format('%Y', o.sales_date), date_format(o.sales_date, '%m')%100, u.gender;