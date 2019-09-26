#include "utility.h"

using namespace std;

int main()
{
	Database db1;
	const char *query1 = "DESCRIBE automation_2013";
	const char *log1 = "1.表的结构";
	db1.query(query1, log1);
	const char *query2 = "SELECT DISTINCT 课程名称 FROM automation_2013 WHERE 课程性质 IN ('专业基础课', '专业方向课', '专业选修课') ORDER BY 学分";
	const char *log2 = "2.查询自动化系的专业课程";
	db1.query(query2,log2);
	const char *query3 = "SELECT 学号,姓名,总成绩 FROM automation_2013 WHERE 课程名称 LIKE '%数学%' ORDER BY 总成绩";
	const char *log3 = "3.数学相关成绩";
	db1.query(query3, log3);
	
	system("pause");
	return 0;
}