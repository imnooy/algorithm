-- 코드를 입력하세요
SELECT b.category, sum(s.sales) as total_sales
from book b, book_sales s
where b.book_id = s.book_id and year(s.sales_date) = 2022 and month(s.sales_date) = 1
group by b.category
order by b.category;
