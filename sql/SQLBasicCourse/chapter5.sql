/*���Ӳ�ѯ*/
use SQLBasicCourse

delete from Product

select * 
from Product

INSERT INTO Product VALUES 
	('0001', 'T����', '�·�', 1000, 500, '2009-09-20');
INSERT INTO Product VALUES 
	('0002', '�����', '�칫��Ʒ', 500, 320, '2009-09-11');
INSERT INTO Product VALUES 
	('0003', '�˶�T��', '�·�', 4000, 2800, NULL);
INSERT INTO Product VALUES 
	('0004', '�˵�', '�����þ�', 3000, 2800, '2009-09-20');
INSERT INTO Product VALUES 
	('0005', '��ѹ��', '�����þ�', 6800, 5000, '2009-01-15');
INSERT INTO Product VALUES 
	('0006', '����', '�����þ�', 500, NULL, '2009-09-20');
INSERT INTO Product VALUES 
	('0007', '���˰�', '�����þ�', 880, 790, '2008-04-28');
INSERT INTO Product VALUES 
	('0008', 'Բ���', '�칫��Ʒ', 100, NULL,'2009-11-11');


/*��ͼ*/
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

	-- ɾ����ͼ
DROP VIEW ProductSum; 
DROP VIEW ProductSum2;


/*�Ӳ�ѯ*/
CREATE VIEW ProductSum (product_type, cnt_product)
AS
SELECT product_type, COUNT(*)
FROM Product
GROUP BY product_type;
-- ȷ�ϴ����õ���ͼ
SELECT product_type, cnt_product
FROM ProductSum;

SELECT product_type, cnt_product
FROM(	SELECT product_type, COUNT(*) AS cnt_product
		FROM Product
		GROUP BY product_type ) AS ProductSum;
		
-- �����Ӳ�ѯ ��ֻ����һ��һ�С���һ�����֣�


/*�����Ӳ�ѯ*/
select product_name,sale_price,product_type
from Product as p1
where sale_price >= (	select avg(sale_price)
					from Product as p2
					where p1.product_type = p2.product_type 
					group by product_type
)