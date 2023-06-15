-- 코드를 입력하세요
SELECT a.apnt_no, p.pt_name, p.pt_no, d.mcdp_cd, d.dr_name, a.apnt_ymd
from patient p, doctor d, appointment a
where a.pt_no=p.pt_no and d.dr_id=a.mddr_id and a.apnt_cncl_yn='N' and date_format(a.apnt_ymd, '%Y-%m-%d') = '2022-04-13' and d.mcdp_cd='CS'
order by a.apnt_ymd;