/*�ۺ�����*/
use SQLBasicCourse;


select *
from product;

/* count avg sum max min*/

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


/* distinct ȥ���ظ���*/
select count(product_type),count(distinct product_type)
from product;


/*���� group by*/
select product_type , count(*)
from product
group by product_type;

/*�Է���ʹ������ having */
select product_type,count(*)
from product 
group by product_type
having count(*)=2;

/*�Բ�ѯ����������� order by */
select product_id,product_name,sale_price,purchase_price
from product 
order by sale_price;

 -- ASC  ascendent�������ģ�
 -- DESC descendent���½��ģ�
select product_id,product_name,purchase_price,sale_price
from product 
order by sale_price DESC;

 -- ָ����������
 select product_id,product_name,purchase_price,sale_price
 from product 
 order by sale_price DESC,purchase_price ASC;

 -- ����ʹ�ñ��
 select product_id,product_name,purchase_price,sale_price
 from product 
 order by 3 DESC,4 ASC;



