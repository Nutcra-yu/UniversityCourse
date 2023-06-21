/*���ݸ���*/

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


/*���ݲ���*/
insert into ProductIns(	product_id ,product_name ,	product_type ,	sale_price,	purchase_price,	regist_date)
				values( '0002' ,	'���˰�',		'�����þ�',		default,	790,			'2023-6-14');

-- ���Ʊ�
INSERT INTO ProductCopy (	product_id, product_name, product_type, sale_price, purchase_price, regist_date)
SELECT						product_id, product_name, product_type, sale_price, purchase_price, regist_date
FROM ProductIns;

INSERT INTO ProductType (	product_type,	sum_sale_price,		sum_purchase_price)
SELECT						product_type,	SUM(sale_price),	SUM(purchase_price)
FROM ProductIns
GROUP BY product_type;


/*����ɾ��*/
-- delete
	-- ��� 
delete from Product;

	-- ָ������
 select * 
 from Product;

 delete from Product
 where sale_price >= 4000


/*���ݸ���*/
update Product
set regist_date = '2023-6-14'

update Product
set sale_price = sale_price *10
where product_type = '�����þ�'; 

update Product
set regist_date = null 
where product_id = '0008';

	-- �ϲ��������
UPDATE Product
SET	sale_price = sale_price * 10,
	purchase_price = purchase_price / 2
WHERE product_type = '�����þ�';
	-- ��ͬ
UPDATE Product
SET (sale_price, purchase_price) = (sale_price * 10, purchase_price / 2)
WHERE product_type = '�����þ�';


/*����*/
BEGIN TRANSACTION;

UPDATE Product
SET sale_price = sale_price - 1000
WHERE product_name = '�˶�T��';
UPDATE Product
SET sale_price = sale_price + 1000
WHERE product_name = 'T����';

COMMIT;