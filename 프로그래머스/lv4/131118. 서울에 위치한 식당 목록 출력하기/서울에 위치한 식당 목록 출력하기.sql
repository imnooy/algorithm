-- 코드를 입력하세요
SELECT i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, round(avg(r.review_score), 2) as score
from rest_info i, rest_review r
where (substring(i.address, 1, 5)='서울특별시' or substring(i.address, 1, 3)='서울시') and i.rest_id=r.rest_id 
group by r.rest_id
order by score desc, favorites desc;