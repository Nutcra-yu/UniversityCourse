	/*查询基础*/
use SQLBasicCourse;

--查询特定列
select product_id, product_name
from product;
--查询所有列
select *
from product;
--查询列 并设置别名
select	product_id as id,
		product_name as name,
		sale_price as "价格"
from product;

--添加常数
select	'2023' as year,
		'03' as month,
		product_id,
		product_name
from product;


--排除重复数据
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
	-- 等同（显示顺序不同）
select distinct sale_price ,product_name
from product;
	--  错误：distinct只能用于第一列之前
select sale_price,distinct product_name 
from product;


-- 条件查询
select *
from product
where product_name = 'eraser'

-- 使用运算
select sale_price ,sale_price*2 as "price*2"
from product;

/*否定*/
-- 不等于号 <>
select product_name 
from product
where product_name <> 'eraser'
-- not
select product_name 
from product
where not product_name <> 'eraser'

--查看null值
select sale_price 
from product 
where sale_price is null
where sale_price is not null
	--sale_price = null 不可行
--查看非null值
select sale_price 
from product 
where sale_price is not null

-- and 和 or 
select product_name,sale_price 
from product 
where	product_name = 'eraser'
 and	sale_price = 2
 or		sale_price = 4
	--and 优先级 高于 or
	--等同于

