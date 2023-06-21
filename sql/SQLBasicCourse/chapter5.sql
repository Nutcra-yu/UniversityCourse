/*复杂查询*/
use SQLBasicCourse

delete from Product

select * 
from Product

INSERT INTO Product VALUES 
	('0001', 'T恤衫', '衣服', 1000, 500, '2009-09-20');
INSERT INTO Product VALUES 
	('0002', '打孔器', '办公用品', 500, 320, '2009-09-11');
INSERT INTO Product VALUES 
	('0003', '运动T恤', '衣服', 4000, 2800, NULL);
INSERT INTO Product VALUES 
	('0004', '菜刀', '厨房用具', 3000, 2800, '2009-09-20');
INSERT INTO Product VALUES 
	('0005', '高压锅', '厨房用具', 6800, 5000, '2009-01-15');
INSERT INTO Product VALUES 
	('0006', '叉子', '厨房用具', 500, NULL, '2009-09-20');
INSERT INTO Product VALUES 
	('0007', '擦菜板', '厨房用具', 880, 790, '2008-04-28');
INSERT INTO Product VALUES 
	('0008', '圆珠笔', '办公用品', 100, NULL,'2009-11-11');


/*视图*/
go;

CREATE VIEW ProductSum (product_type, cnt_product)
AS
SELECT product_type, COUNT(*)
FROM Product
GROUP BY product_type;
go;

CREATE VIEW ProductSum2 (type_sum)
AS
SELECT count(*)
FROM ProductSum;

go;

SELECT product_type, cnt_product
FROM ProductSum;

SELECT * 
FROM ProductSum2

	-- 删除试图
DROP VIEW ProductSum; 
DROP VIEW ProductSum2;


/*子查询*/
CREATE VIEW ProductSum (product_type, cnt_product)
AS
SELECT product_type, COUNT(*)
FROM Product
GROUP BY product_type;
-- 确认创建好的视图
SELECT product_type, cnt_product
FROM ProductSum;

SELECT product_type, cnt_product
FROM(	SELECT product_type, COUNT(*) AS cnt_product
		FROM Product
		GROUP BY product_type ) AS ProductSum;
		
-- 标量子查询 （只返回一行一列。即一个数字）


/*关联子查询*/
select product_name,sale_price,product_type
from Product as p1
where sale_price >= (	select avg(sale_price)
					from Product as p2
					where p1.product_type = p2.product_type 
					group by product_type
)