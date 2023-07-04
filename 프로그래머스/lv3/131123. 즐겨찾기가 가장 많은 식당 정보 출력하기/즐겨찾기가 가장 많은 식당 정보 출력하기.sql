-- 코드를 입력하세요
select max(favorites), food_type
from rest_info
group by food_type;

select food_type, rest_id, rest_name, favorites
from rest_info, (
    select max(favorites) as f, food_type as t
    from rest_info
    group by food_type
) as tmp
where tmp.f = rest_info.favorites and tmp.t = rest_info.food_type
order by food_type desc;

