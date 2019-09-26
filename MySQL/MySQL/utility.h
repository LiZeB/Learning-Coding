#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <cstring>
#pragma comment(lib,"D:\\Program Files (x86)\\mysql-5.7.20-winx64\\mysql-5.7.20-winx64\\lib\\libmysql.lib")

using namespace std;

class Database {
public:
	Database(const char user[] = "root", const char pswd[] = "123", const char host[] = "localhost",
		const char dbname[] = "students", const char table[] = "automation_2013", unsigned int port = 3306);
	~Database();
	void query(const char *query, const char *log_indicator);
public:
	MYSQL *myCont;
	bool flag;
	ofstream out_file = ofstream("自动化2013级.txt", ofstream::app);
};