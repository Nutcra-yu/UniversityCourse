/*数据更新*/

USE SQLBasicCourse

CREATE TABLE ProductIns
(
product_id		CHAR(4)			NOT NULL,
product_name	VARCHAR(100)	NOT NULL,
product_type	VARCHAR(32)		NOT NULL,
sale_price		INTEGER			DEFAULT 0,
purchase_price	INTEGER ,
regist_date		DATE ,
PRIMARY KEY (product_id)
 );

 CREATE TABLE ProductCopy
(
product_id		CHAR(4)			NOT NULL,
product_name	VARCHAR(100)	NOT NULL,
product_type	VARCHAR(32)		NOT NULL,
sale_price		INTEGER ,
purchase_price	INTEGER ,
regist_date DATE ,
PRIMARY KEY (product_id)
);

CREATE TABLE ProductType
(
product_type		VARCHAR(32)		NOT NULL,
sum_sale_price		INTEGER ,
sum_purchase_price	INTEGER ,
PRIMARY KEY (product_type)
);

 select * 
 from ProductIns;

 select *
 from ProductCopy;

 select *
 from ProductType;

drop table ProductIns;
drop table ProductCopy;
drop table ProductType;


/*数据插入*/
insert into ProductIns(	product_id ,product_name ,	product_type ,	sale_price,	purchase_price,	regist_date)
				values( '0002' ,	'擦菜板',		'厨房用具',		default,	790,			'2023-6-14');

-- 复制表
INSERT INTO ProductCopy (	product_id, product_name, product_type, sale_price, purchase_price, regist_date)
SELECT						product_id, product_name, product_type, sale_price, purchase_price, regist_date
FROM ProductIns;

INSERT INTO ProductType (	product_type,	sum_sale_price,		sum_purchase_price)
SELECT						product_type,	SUM(sale_price),	SUM(purchase_price)
FROM ProductIns
GROUP BY product_type;


/*数据删除*/
-- delete
	-- 清空 
delete from Product;

	-- 指定对象
 select * 
 from Product;

 delete from Product
 where sale_price >= 4000


/*数据更新*/
update Product
set regist_date = '2023-6-14'

update Product
set sale_price = sale_price *10
where product_type = '厨房用具'; 

update Product
set regist_date = null 
where product_id = '0008';

	-- 合并多条语句
UPDATE Product
SET	sale_price = sale_price * 10,
	purchase_price = purchase_price / 2
WHERE product_type = '厨房用具';
	-- 等同
UPDATE Product
SET (sale_price, purchase_price) = (sale_price * 10, purchase_price / 2)
WHERE product_type = '厨房用具';


/*事务*/
BEGIN TRANSACTION;

UPDATE Product
SET sale_price = sale_price - 1000
WHERE product_name = '运动T恤';
UPDATE Product
SET sale_price = sale_price + 1000
WHERE product_name = 'T恤衫';

COMMIT;