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


INSERT INTO S VALUES('S1','����',20,'���');
INSERT INTO S VALUES('S2','ʢ��',10,'����');
INSERT INTO S VALUES('S3','������',30,'����');
INSERT INTO S VALUES('S4','��̩ʢ',20,'���');
INSERT INTO S VALUES('S5','Ϊ��',30,'�Ϻ�');
 
INSERT INTO P VALUES('P1','��ĸ','��',12);
INSERT INTO P VALUES('P2','��˨','��',17);
INSERT INTO P VALUES('P3','��˿��','��',14);
INSERT INTO P VALUES('P4','��˿��','��',14);
INSERT INTO P VALUES('P5','͹��','��',40);
INSERT INTO P VALUES('P6','����','��',30);
 
INSERT INTO J VALUES('J1','����','����');
INSERT INTO J VALUES('J2','һ��','����');
INSERT INTO J VALUES('J3','���ɳ�','���');
INSERT INTO J VALUES('J4','�촬��','���');
INSERT INTO J VALUES('J5','������','��ɽ');
INSERT INTO J VALUES('J6','���ߵ糧','����');
INSERT INTO J VALUES('J7','�뵼�峧','�Ͼ�');
 
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




/*��ѯ*/
/*ϰ����*/
--��Ӧ����J1����Ĺ�Ӧ�̺���SNO
select SNO,JNO
from SPJ
where JNO= 'J1';

--��Ӧ����J1���P1�Ĺ�Ӧ�̺���SNO
select SNO,JNO,PNO
from SPJ
where (JNO= 'J1' and PNO = 'P1');

--��Ӧ����J1���Ϊ��ɫ�Ĺ�Ӧ�̺���SNO��
select SNO 
from SPJ 
where PNO IN (	select PNO 
				from P 
				where COLOR='��')
	  and JNO = 'J1';

--��û��ʹ�����Ӧ�������ĺ�ɫ����Ĺ��̺�JNO��
select JNO
from SPJ
where  (SNO in (select SNO from S where CITY <> '���')
	and PNO in (select PNO from P where COLOR <> '��'));

--������ʹ���˹�Ӧ��S1����Ӧ��ȫ������Ĺ��̺�JNO��
select JNO ,SNO
from SPJ 
where SNO='S1' 


/*ϰ����*/
--��Ӧ�̵����ֺͳ���
select SNAME , CITY
from S

--�����������ɫ����
select PNAME,COLOR,WEIGHT
from P
--S1����Ӧ����Ĺ��̺���JNO
select JNO
from SPJ
where SNO = 'S1'
--J2ʹ�õĸ�����������ƺ�����
select PNAME ,QTY
from P,SPJ
where	spj.pno = p.pno
	and spj.jno = 'J2'
--�Ϻ����̹�Ӧ�������������
select distinct PNO
from SPJ
where SNO in (select sno from S where CITY = '�Ϻ�')
--ʹ���Ϻ�����Ĺ�������
select JNAME
from J
where JNO in (select JNO from SPJ where SNO in (select SNO from S where CITY= '�Ϻ�'))
--�ҳ�û��ʹ������������Ĺ��̺���;
select distinct JNO
from SPJ
where SNO  not in (select SNO from S where CITY = '���')
