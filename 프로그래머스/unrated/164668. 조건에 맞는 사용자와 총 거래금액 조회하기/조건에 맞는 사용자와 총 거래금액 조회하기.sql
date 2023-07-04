-- 코드를 입력하세요
SELECT u.user_id, u.nickname, sum(b.price) as total_sales
from used_goods_board b, used_goods_user u
where b.writer_id = u.user_id and status='DONE'
group by b.writer_id
having sum(b.price)>=700000
order by total_sales;