	/*��ѯ����*/
use SQLBasicCourse;

--��ѯ�ض���
select product_id, product_name
from product;
--��ѯ������
select *
from product;
--��ѯ�� �����ñ���
select	product_id as id,
		product_name as name,
		sale_price as "�۸�"
from product;

--��ӳ���
select	'2023' as year,
		'03' as month,
		product_id,
		product_name
from product;


--�ų��ظ�����
select product_type
from product;
select distinct product_type
from product;

select purchase_price
from product;
select distinct purchase_price
from product;

select distinct product_type,purchase_price
from product;
	-- ��ͬ����ʾ˳��ͬ��
select distinct sale_price ,product_name
from product;
	--  ����distinctֻ�����ڵ�һ��֮ǰ
select sale_price,distinct product_name 
from product;


-- ������ѯ
select *
from product
where product_name = 'eraser'

-- ʹ������
select sale_price ,sale_price*2 as "price*2"
from product;

/*��*/
-- �����ں� <>
select product_name 
from product
where product_name <> 'eraser'
-- not
select product_name 
from product
where not product_name <> 'eraser'

--�鿴nullֵ
select sale_price 
from product 
where sale_price is null
where sale_price is not null
	--sale_price = null ������
--�鿴��nullֵ
select sale_price 
from product 
where sale_price is not null

-- and �� or 
select product_name,sale_price 
from product 
where	product_name = 'eraser'
 and	sale_price = 2
 or		sale_price = 4
	--and ���ȼ� ���� or
	--��ͬ��

