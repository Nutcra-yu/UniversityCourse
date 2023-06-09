use class;

--Student
create table Student
(
Sno		char(9)	 ,
Sname	char(20) unique,
Ssex	char(2),
Sage	smallint,
Sdept	char(20),
primary key(Sno)
);

insert into Student values ('201215121','����','��',20,'CS');
insert into Student values('201215122','����','Ů',19,'CS');
insert into Student values('201215123','����','Ů',19,'MA');
insert into Student values('201215125','����','��',19,'IS');

select * from Student;

--Course 
create table Course
(
Cno		char(4)	 primary key,
Cname	char(40) not null,
Cpno	char(4),
Ccredit	smallint,
foreign key(Cpno) references Course (Cno)
); 

insert into Course(Cno,Cname)values('1','���ݿ�');
insert into Course(Cno,Cname)values('2','��ѧ');
insert into Course(Cno,Cname)values('3','��Ϣϵͳ');
insert into Course(Cno,Cname)values('4','����ϵͳ');
insert into Course(Cno,Cname)values('5','���ݽṹ');
insert into Course(Cno,Cname)values('6','���ݴ���');
insert into Course(Cno,Cname)values('7','PASCAL����');

update Course set Cpno='5', Ccredit = 4 where Cno = '1';
update Course set Cpno=null,Ccredit = 2 where Cno = '2';
update Course set Cpno='1', Ccredit = 4 where Cno = '3';
update Course set Cpno='6', Ccredit = 3 where Cno = '4';
update Course set Cpno='7', Ccredit = 4 where Cno = '5';
update Course set Cpno=null,Ccredit = 2 where Cno = '6';
update Course set Cpno='6', Ccredit = 4 where Cno = '7';

select * from Course;


--SC
create table SC
(
Sno		char(9),
Cno		char(4),
Grade	smallint,
primary key(Sno,Cno),
foreign key(Sno) references Student(Sno),
foreign key(Cno) references Course(Cno)
);


insert into SC values('201215121','1',92);
insert into SC values('201215121','2',85);
insert into SC values('201215121','3',88);
insert into SC values('201215122','2',90);
insert into SC values('201215122','3',80);

select *from SC; 



use class
go
create schema student
go
alter  schema student transfer object ::Student

use class
go
create schema teacher
go
alter  schema teacher transfer object ::Student
alter  schema teacher transfer object ::Course
alter  schema teacher transfer object ::SC

