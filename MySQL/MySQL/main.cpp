#include "utility.h"

using namespace std;

int main()
{
	Database db1;
	const char *query1 = "DESCRIBE automation_2013";
	const char *log1 = "1.��Ľṹ";
	db1.query(query1, log1);
	const char *query2 = "SELECT DISTINCT �γ����� FROM automation_2013 WHERE �γ����� IN ('רҵ������', 'רҵ�����', 'רҵѡ�޿�') ORDER BY ѧ��";
	const char *log2 = "2.��ѯ�Զ���ϵ��רҵ�γ�";
	db1.query(query2,log2);
	const char *query3 = "SELECT ѧ��,����,�ܳɼ� FROM automation_2013 WHERE �γ����� LIKE '%��ѧ%' ORDER BY �ܳɼ�";
	const char *log3 = "3.��ѧ��سɼ�";
	db1.query(query3, log3);
	
	system("pause");
	return 0;
}