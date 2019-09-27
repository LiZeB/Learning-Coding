#include "dictOrder.h"
#include "my_sort.h"
#include "my_search.h"
#include "graph.h"
#include "recursion.h"

int main()
{
	cout << "***********�����ֵ���**********" << endl;
	test_dictOrder();

	cout << "**************��������*********" << endl;
	test_sort();

	cout << "*********���Զ��ֲ���***********" << endl;
	test_search();

	cout << "**********����Dijkstra�㷨******" << endl;
	test_dijkstra();

	cout << "*********���Եݹ��㷨************" << endl;
	test_recursion();

	getchar();
	return 0;
}