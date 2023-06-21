/*����*/
use SQLBasicCourse;

/*��������*/


/*ν�� ����ֵ����ֵ�ĺ���*/
CREATE TABLE SampleLike
( 
strcol VARCHAR(6) NOT NULL,
PRIMARY KEY (strcol)
);

INSERT INTO SampleLike (strcol) VALUES ('abcddd');
INSERT INTO SampleLike (strcol) VALUES ('dddabc');
INSERT INTO SampleLike (strcol) VALUES ('abdddc');
INSERT INTO SampleLike (strcol) VALUES ('abcdd');
INSERT INTO SampleLike (strcol) VALUES ('ddabc');
INSERT INTO SampleLike (strcol) VALUES ('abddc');

drop table SampleLike;

select * from SampleLike;

SELECT *
FROM SampleLike
WHERE strcol LIKE '%ddd%';SELECT *
FROM SampleLike
WHERE strcol LIKE 'abc%';SELECT *
FROM SampleLike
WHERE strcol LIKE 'a_d_c';
SELECT product_name, sale_price
FROM Product
WHERE sale_price BETWEEN 100 AND 1000;

SELECT product_name, sale_price
FROM Product
WHERE sale_price > 100 AND  sale_price < 1000;

	-- in
CREATE TABLE ShopProduct
(
shop_id		CHAR(4)			NOT NULL,
shop_name	VARCHAR(200)	NOT NULL,
product_id	CHAR(4)			NOT NULL,
quantity	INTEGER			NOT NULL,
PRIMARY KEY (shop_id, product_id));
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '����', '0001', 30);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '����', '0002', 50);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000A', '����', '0003', 15);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '������', '0002', 30);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '������', '0003', 120);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '������', '0004', 20);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '������', '0006', 10);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000B', '������', '0007', 40);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '����', '0003', 20);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '����', '0004', 50);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '����', '0006', 90);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000C', '����', '0007', 70);
INSERT INTO ShopProduct (shop_id, shop_name, product_id, quantity) VALUES ('000D', '����', '0001', 100);
select * from ShopProduct;

select product_name,sale_price
from Product
where product_id in (	select product_id
						from ShopProduct
						where shop_name = '����')

SELECT product_name, sale_price
FROM Product AS P 
WHERE EXISTS (	SELECT *
				FROM ShopProduct AS SP 
				WHERE	SP.shop_id = '000C'
					AND	SP.product_id = P.product_id);

SELECT  product_name,product_type
from Product
where exists (	select *
				from ShopProduct
				where shop_id = '000C'
				and quantity > 30)

SELECT  product_name,product_type,quantity,shop_id
from Product,ShopProduct
where exists (	select *
				from ShopProduct
				where shop_id = '000C'
				and quantity > 30);


/*case*/
SELECT product_name,
	CASE	WHEN product_type = '�·�'
			THEN 'A ��' || product_type
			WHEN product_type = '�칫��Ʒ'
			THEN 'B ��' || product_type
			WHEN product_type = '�����þ�'
			THEN 'C ��' || product_type
			ELSE NULL
	END AS abc_product_type
FROM Product;

SELECT product_name,
    CASE
        WHEN product_type = '�·�'		THEN CONCAT('A ��', product_type)
        WHEN product_type = '�칫��Ʒ'	THEN CONCAT('B ��', product_type)
        WHEN product_type = '�����þ�'	THEN CONCAT('C ��', product_type)
        ELSE NULL
    END AS abc_product_type
FROM Product;

SELECT product_type,SUM(sale_price) AS 'type_sum_price'
FROM Product
GROUP BY product_type

SELECT	SUM(CASE WHEN product_type = '�·�'		THEN sale_price ELSE 0 END) AS sum_price_clothes,
		SUM(CASE WHEN product_type = '�����þ�' THEN sale_price ELSE 0 END) AS sum_price_kitchen,
		SUM(CASE WHEN product_type = '�칫��Ʒ' THEN sale_price ELSE 0 END) AS sum_price_office
FROM Product;