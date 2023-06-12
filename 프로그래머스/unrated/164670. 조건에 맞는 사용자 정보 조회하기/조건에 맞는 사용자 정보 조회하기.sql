-- 코드를 입력하세요
select u.user_id as USER_ID, u.nickname as NICKNAME, concat(u.city, " ", u.street_address1, " ", street_address2) as 전체주소, concat(substr(u.tlno, 1, 3), "-", substr(u.tlno, 4, 4), "-", substr(u.tlno, 8, 4)) as 전화번호
from used_goods_user u, used_goods_board b
where b.writer_id=u.user_id
group by b.writer_id
having count(b.writer_id)>=3
order by u.user_id desc;