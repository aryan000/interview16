-----------------------
SQL Constraints : 
-----------------------
	NOT NULL
	Default
	Unique
	Primary Key
	Foreign Key
	Check
	Index


1) Not NULL : 
-----------------
	eg : 
		Create table student(
			rollno int Not NUll,
			name varchar {20}
			primary key(rollno)
			);

	To add a NOt null constraint 
	eg : 
	 alter table student
	 modify name varchar{40} not null;

2) Default Constraint :
----------------------------------
	create table employee(
		id int not null,
		salary decimal(20,4) default 10000.0000
		);

	To add a default constraint :
	eg : 
	alter table employee
	 modify salary decimal(20,2) default;

	 To Drop a default constraint : 
	 eg : 
	 alter table employee
	 alter column salary drop default;

3) Unique Constraint :
-------------------------------
	create table student (
		rollno int not null , 
		id , int unique );



------------------------------------------------------------------
SQL Syntax
------------------------------------------------------------------

1) SQL SELECT
	
	syntax : select column1 , column2 .... columnN from table_name;
2) Distinct Clause ;
select distinct column1 , column2 , column3 from table_name;

3) SQL where clause : 
select * from table_name where condition ;

4) SQL and/or clause : 
select *from table_name where condition1 and|or condition2

5) SQL IN clause ;
select *from table_name where column_name in (value2, value3);

6) SQL between clause : 
select *from table_name where column_name between (value2 , value2);

7) SQL like clause  : 
select *from table_name where column_name like (Pattern);

// Patterns 
//  %abc  -- word ending with abc
// abc%  -- word starting with abc
//%abc% -- word which has abc in between 


8)SQL Order by 
select count(city) from table_name where condition group by column_name;

9) SQL count clause : 
select count(column_name) from table_name where condition;

10) SQL having clause :
select sum(column_name) from table_name where condition group by column_name having (arithmetic function );


