#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
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
	if (mysql_real_connect(&myCont, host, user, pswd, dbname, port, NULL, 0))
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
		res = mysql_query(&myCont, "select * from automation_2013");//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					cout << sql_row[1]<<sql_row[2] << endl;
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	
	system("pause");
	return 0;
}