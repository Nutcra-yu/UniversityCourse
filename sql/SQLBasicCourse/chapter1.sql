use SQLBasicCourse;

-- 建表
create table product
(
product_id		int			not null,
product_name	varchar(20) not null,
product_type	varchar(20),
sale_price		int			not null,
purchase_sale	int			not null,
register_date	date,
primary key (product_id)
);

-- 删表
drop table product;

-- 添列
alter table product add purchase_price integer;
alter table product add product_type char(20);
alter table product add purchase_price integer;
alter table product add register_date date;

-- 删列
alter table product drop column purchase_price;
alter table product drop column product_name;
alter table product drop column sale_price;
-- 主键
alter table product drop column product_id


-- 插入数据
begin transaction;

insert into product values 
	(001,'T-shirt','cloth',1000,500,'2023-09-20');
insert into product values
	(002,'puncher','office supplies',500,320,'2023-09-11');
insert into product values
	(003,'short T-shirt','cloth',4000,2800,null);
insert into product values
	(004,'kitchen knife','kitchenware',3000,2800,'2023-09-20');
insert into product values
	(005,'prseeure cooker','kitchenware',6800,5000,'2023-01-15');
insert into product values
	(006,'fork','kitchenware',500,400,'2023-09-2');
insert into product values
	(007,'rasp','kitchenware',880,790,'2022-04-28');
insert into product values
	(008,'ball-point-pencile','office supplies',100,50,'2023-11-11')

commit;

-- 修改列名
exec sp_rename 'product.purchase_sale','purchase_price','column'

-- 重命名数据库
alter database zyu modify name = SQLBasicCourse;
