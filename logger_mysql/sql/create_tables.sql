/* 
 * mysql create table script
 */

create table data (
	date_logged timestamp not null,
	data decimal(10,5) not null
)
engine innodb
default character set utf8;