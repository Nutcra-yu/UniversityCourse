/*�ۺ�����*/
use SQLBasicCourse;


select *
from product;


/*��������*/
select count(*)
from product;
-- ����ǿ�����
select	count(*), count(register_date)
from product;


/*�����*/
select SUM(sale_price),sum(purchase_price)
from product;


/*ƽ��ֵ*/
select avg(purchase_price),avg(sale_price)
from product;


/*�����Сֵ*/
select max(purchase_price),min(purchase_price)
from product;


/*ȥ���ظ���*/
select count(product_type),count(distinct product_type)
from product;