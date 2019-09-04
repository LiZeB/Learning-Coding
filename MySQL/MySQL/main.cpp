#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <cstring>
#pragma comment(lib,"D:\\Program Files (x86)\\mysql-5.7.20-winx64\\mysql-5.7.20-winx64\\lib\\libmysql.lib")

using namespace std;

int main()
{
	const char user[] = "root";
	const char pswd[] = "123";
	const char host[] = "localhost";
	const char dbname[] = "students";
	const char table[] = "automation_2013";
	unsigned int port = 3306;
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res;
	mysql_init(&myCont);

	ofstream out_file("自动化2013级.txt", ofstream::out);

	if (!mysql_real_connect(&myCont, host, user, pswd, dbname, port, NULL, 0)) {
		cout << "connect failed!" << endl;
		system("pause");
		return 0;
	}
	
	/***************查询专业课信息*****************/
	mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
	const char query1[] = "select distinct 课程名称, 学时, 学分, 开课单位 from automation_2013 where 课程性质 in ('专业基础课', '专业方向课', '专业选修课')";
	res = mysql_query(&myCont, query1);//查询
	out_file << "1.自动化专业相关课程：" << endl;
	if (!res){
		result = mysql_store_result(&myCont);
		if (result){
			unsigned int num_fields = mysql_num_fields(result);
			while (sql_row = mysql_fetch_row(result)){
				for (unsigned int i = 0; i < num_fields; i++) {
					cout << (sql_row[i] ? sql_row[i] : "NULL") << endl;
					out_file << (sql_row[i] ? sql_row[i] : "NULL") <<" ";
				}
				out_file << endl;
			}
		}
	}
	else{
		cout << "query sql failed!" << endl;
	}
	
	/****************用上面查询的结果创建一个新表*********/
	char query2[200] = "CREATE TABLE Curriculum AS ";   //注意这里要加空格
	strcat(query2, query1);
	cout << query2 << endl;
	mysql_query(&myCont, query2);

	/*****************将某一个非主键属性设置为主键********/
	/*char *query3 = "ALETER TABLE Automation_2013 ADD PRIMARY KEY(学号)";
	mysql_query(&myCont, query3);
	char *query4 = "ALETER TABLE Curriculum ADD PRIMARY KEY(课程名称)";
	mysql_query(&myCont, query4);*/
	
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	
	system("pause");
	return 0;
}