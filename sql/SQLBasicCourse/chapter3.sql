/*聚合排序*/
use SQLBasicCourse;


select *
from product;


/*计算行数*/
select count(*)
from product;
-- 计算非空行数
select	count(*), count(register_date)
from product;


/*列求和*/
select SUM(sale_price),sum(purchase_price)
from product;


/*平均值*/
select avg(purchase_price),avg(sale_price)
from product;


/*最大最小值*/
select max(purchase_price),min(purchase_price)
from product;


/*去除重复项*/
select count(product_type),count(distinct product_type)
from product;