-- 코드를 입력하세요
select c.car_id, (
    case when c.car_id in (
    select car_id
    from car_rental_company_rental_history
    where datediff(start_date, date('2022-10-16')) <= 0 and datediff(end_date, date('2022-10-16')) >= 0
    )
    then '대여중' 
    else '대여 가능' end
) as availability
from car_rental_company_rental_history c
group by c.car_id
order by c.car_id desc;
;
