create table S
(
SNO		char(10) primary key,
SNAME	char(10),
STATUS	char(3),
CITY	char(20),
);

CREATE TABLE P
(
PNO		char(10) primary key,
PNAME	char(20) NOT NULL,
COLOR	char(10),
WEIGHT	char(2),
);

CREATE TABLE J
(
JNO		char(10) primary key,
JNAME	char(20) NOT NULL,
CITY	char(20),
);

CREATE TABLE SPJ
(
SNO char(10),
PNO char(10),
JNO char(10),
QTY char(3),
foreign key (SNO) references S(SNO),
foreign key (PNO) references P(PNO),
foreign key (JNO) references J(JNO),
);


INSERT INTO S VALUES('S1','精益',20,'天津');
INSERT INTO S VALUES('S2','盛锡',10,'北京');
INSERT INTO S VALUES('S3','东方红',30,'北京');
INSERT INTO S VALUES('S4','丰泰盛',20,'天津');
INSERT INTO S VALUES('S5','为民',30,'上海');
 
INSERT INTO P VALUES('P1','螺母','红',12);
INSERT INTO P VALUES('P2','螺栓','绿',17);
INSERT INTO P VALUES('P3','螺丝刀','蓝',14);
INSERT INTO P VALUES('P4','螺丝刀','红',14);
INSERT INTO P VALUES('P5','凸轮','蓝',40);
INSERT INTO P VALUES('P6','齿轮','红',30);
 
INSERT INTO J VALUES('J1','三建','北京');
INSERT INTO J VALUES('J2','一汽','长春');
INSERT INTO J VALUES('J3','弹簧厂','天津');
INSERT INTO J VALUES('J4','造船厂','天津');
INSERT INTO J VALUES('J5','机车厂','唐山');
INSERT INTO J VALUES('J6','无线电厂','常州');
INSERT INTO J VALUES('J7','半导体厂','南京');
 
INSERT INTO SPJ VALUES('S1','P1','J1',200);
INSERT INTO SPJ VALUES('S1','P1','J3',100);
INSERT INTO SPJ VALUES('S1','P1','J4',700);
INSERT INTO SPJ VALUES('S1','P2','J2',100);
INSERT INTO SPJ VALUES('S2','P3','J1',400);
INSERT INTO SPJ VALUES('S2','P3','J2',200);
INSERT INTO SPJ VALUES('S2','P3','J4',500);
INSERT INTO SPJ VALUES('S2','P3','J5',400);
INSERT INTO SPJ VALUES('S2','P5','J1',400);
INSERT INTO SPJ VALUES('S2','P5','J2',100);
INSERT INTO SPJ VALUES('S3','P1','J1',200);
INSERT INTO SPJ VALUES('S3','P3','J1',200);
INSERT INTO SPJ VALUES('S4','P5','J1',100);
INSERT INTO SPJ VALUES('S4','P6','J3',300);
INSERT INTO SPJ VALUES('S4','P6','J4',200);
INSERT INTO SPJ VALUES('S5','P2','J4',100);
INSERT INTO SPJ VALUES('S5','P3','J1',200);
INSERT INTO SPJ VALUES('S5','P6','J2',200);
INSERT INTO SPJ VALUES('S5','P6','J4',500);

select * from S;
select * from P;
select * from J;
select * from SPJ;




/*查询*/
/*习题四*/
--求供应工程J1零件的供应商号码SNO
select SNO,JNO
from SPJ
where JNO= 'J1';

--求供应工程J1零件P1的供应商号码SNO
select SNO,JNO,PNO
from SPJ
where (JNO= 'J1' and PNO = 'P1');

--求供应工程J1零件为红色的供应商号码SNO；
select SNO 
from SPJ 
where PNO IN (	select PNO 
				from P 
				where COLOR='红')
	  and JNO = 'J1';

--求没有使用天津供应商生产的红色零件的工程号JNO；
select JNO
from SPJ
where  (SNO in (select SNO from S where CITY <> '天津')
	and PNO in (select PNO from P where COLOR <> '红'));

--求至少使用了供应商S1所供应的全部零件的工程号JNO；
select JNO ,SNO
from SPJ 
where SNO='S1' 


/*习题五*/
--供应商的名字和城市
select SNAME , CITY
from S

--零件的名称颜色重量
select PNAME,COLOR,WEIGHT
from P
--S1所供应零件的工程号码JNO
select JNO
from SPJ
where SNO = 'S1'
--J2使用的各种零件的名称和数量
select PNAME ,QTY
from P,SPJ
where	spj.pno = p.pno
	and spj.jno = 'J2'
--上海厂商供应的所有零件号码
select distinct PNO
from SPJ
where SNO in (select sno from S where CITY = '上海')
--使用上海零件的工程名称
select JNAME
from J
where JNO in (select JNO from SPJ where SNO in (select SNO from S where CITY= '上海'))
--找出没有使用天津产的零件的工程号码;
select distinct JNO
from SPJ
where SNO  not in (select SNO from S where CITY = '天津')
