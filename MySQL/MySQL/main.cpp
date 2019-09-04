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

	ofstream out_file("�Զ���2013��.txt", ofstream::out);

	if (!mysql_real_connect(&myCont, host, user, pswd, dbname, port, NULL, 0)) {
		cout << "connect failed!" << endl;
		system("pause");
		return 0;
	}
	
	/***************��ѯרҵ����Ϣ*****************/
	mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ
	const char query1[] = "select distinct �γ�����, ѧʱ, ѧ��, ���ε�λ from automation_2013 where �γ����� in ('רҵ������', 'רҵ�����', 'רҵѡ�޿�')";
	res = mysql_query(&myCont, query1);//��ѯ
	out_file << "1.�Զ���רҵ��ؿγ̣�" << endl;
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
	
	/****************�������ѯ�Ľ������һ���±�*********/
	char query2[200] = "CREATE TABLE Curriculum AS ";   //ע������Ҫ�ӿո�
	strcat(query2, query1);
	cout << query2 << endl;
	mysql_query(&myCont, query2);

	/*****************��ĳһ����������������Ϊ����********/
	/*char *query3 = "ALETER TABLE Automation_2013 ADD PRIMARY KEY(ѧ��)";
	mysql_query(&myCont, query3);
	char *query4 = "ALETER TABLE Curriculum ADD PRIMARY KEY(�γ�����)";
	mysql_query(&myCont, query4);*/
	
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	
	system("pause");
	return 0;
}