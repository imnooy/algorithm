-- 코드를 입력하세요
select m.member_name, r.review_text, date_format(r.review_date, '%Y-%m-%d') as review_date
from member_profile m right join rest_review r
on m.member_id=r.member_id
where m.member_name in (
    select m.member_name
    from member_profile m right join rest_review r
    on m.member_id=r.member_id
    group by r.member_id
    having count(r.member_id)=(
        select count(*)
        from rest_review t
        group by t.member_id
        having count(t.member_id)
        order by count(*) desc
        limit 1
    )
)
order by r.review_date, r.review_text;

-- ------------------------
# select m.member_name
# from member_profile m right join rest_review r
# on m.member_id=r.member_id
# group by r.member_id
# having count(r.member_id)=(
#     select count(*)
#     from rest_review t
#     group by t.member_id
#     having count(t.member_id)
#     order by count(*) desc
#     limit 1
# );

