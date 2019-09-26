#include "utility.h"

Database::Database(const char user[] , const char pswd[], const char host[],
	const char dbname[] , const char table[], unsigned int port)
{
	myCont = new MYSQL();
	mysql_init(myCont);
	if (mysql_real_connect(myCont, host, user, pswd, dbname, port, NULL, 0)) {
		flag = true;
		mysql_query(myCont, "SET NAMES GBK");    //设置编码格式
	}
	else {
		flag = false;
	}
}

Database::~Database() {
	if(flag)
		mysql_close(myCont);
}

void  Database::query(const char *query, const char *log_indicator) {
	if (!flag) {
		cout << "Connected Failed!" << endl;
		return;
	}

	int res = mysql_query(myCont, query);//查询
	MYSQL_RES *result;
	MYSQL_ROW sql_row;

	if (!res) {
		result = mysql_store_result(myCont);
		out_file << log_indicator << endl;
		if (result) {
			unsigned int num_fields = mysql_num_fields(result);
			while (sql_row = mysql_fetch_row(result)) {
				for (unsigned int i = 0; i < num_fields; i++) {
					cout << (sql_row[i] ? sql_row[i] : "NULL") << endl;
					out_file << (sql_row[i] ? sql_row[i] : "NULL") << " ";
				}
				out_file << endl;
			}
		}

		if (result != NULL)
			mysql_free_result(result);
	}
	else {
		cout << "query sql failed!" << endl;
	}
}