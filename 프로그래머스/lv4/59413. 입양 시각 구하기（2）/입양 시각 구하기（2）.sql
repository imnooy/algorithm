-- 코드를 입력하세요
with recursive temp as (
    select 0 as hour
    union all
    select hour+1 from temp where hour<23
)

SELECT t.hour, ifnull(count(h.animal_id), 0) as count
from temp t left outer join (
    select o.animal_id, hour(o.datetime) as hour
    from animal_outs o
) as h
on t.hour=h.hour
group by t.hour
order by t.hour;

# select hour(datetime), count(hour(datetime))
# from animal_outs
# group by hour(datetime)
# order by hour(datetime);