/*聚合排序*/
use SQLBasicCourse;


select *
from product;

/* count avg sum max min*/

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


/* distinct 去除重复项*/
select count(product_type),count(distinct product_type)
from product;


/*分组 group by*/
select product_type , count(*)
from product
group by product_type;

/*对分组使用条件 having */
select product_type,count(*)
from product 
group by product_type
having count(*)=2;

/*对查询结果进行排序 order by */
select product_id,product_name,sale_price,purchase_price
from product 
order by sale_price;

 -- ASC  ascendent（上升的）
 -- DESC descendent（下降的）
select product_id,product_name,purchase_price,sale_price
from product 
order by sale_price DESC;

 -- 指定多个排序键
 select product_id,product_name,purchase_price,sale_price
 from product 
 order by sale_price DESC,purchase_price ASC;

 -- 可以使用编号
 select product_id,product_name,purchase_price,sale_price
 from product 
 order by 3 DESC,4 ASC;



