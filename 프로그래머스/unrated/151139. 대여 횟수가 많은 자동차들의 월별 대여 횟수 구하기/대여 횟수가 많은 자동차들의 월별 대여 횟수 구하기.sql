-- 코드를 입력하세요
SELECT count(*), car_id, month(start_date)
from car_rental_company_rental_history
where month(start_date)>=8 && month(start_date)<=10
group by car_id
having count(*)>=5
;


# SELECT month(start_date) as month, car_id, count(month(start_date)) as record
# from car_rental_company_rental_history
# where month(start_date)>=8 && month(start_date)<=10
# group by car_id
# having count(*)>=5
# ;

select month(start_date) as month, car_id, count(*) as records
from car_rental_company_rental_history c, (
    SELECT car_id as cid
    from car_rental_company_rental_history
    where month(start_date)>=8 && month(start_date)<=10
    group by car_id
    having count(*)>=5
) tmp
where tmp.cid = c.car_id && month(start_date)>=8 && month(start_date)<=10
group by car_id, month(start_date)
order by month(start_date), car_id desc
;

# select * from car_rental_company_rental_history;