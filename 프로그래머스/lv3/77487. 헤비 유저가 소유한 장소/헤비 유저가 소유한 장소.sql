-- 코드를 입력하세요
SELECT id
from places
group by host_id
having count(*) >= 2
order by id;

select p.id, p.name, p.host_id
from places p, (
    SELECT host_id
    from places
    group by host_id
    having count(*) >= 2
) as tmp
where p.host_id = tmp.host_id
order by id;