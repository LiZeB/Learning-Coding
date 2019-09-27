#include "dictOrder.h"
#include "my_sort.h"
#include "my_search.h"
#include "graph.h"
#include "recursion.h"

int main()
{
	cout << "***********²âÊÔ×ÖµäÐò**********" << endl;
	test_dictOrder();

	cout << "**************²âÊÔÅÅÐò*********" << endl;
	test_sort();

	cout << "*********²âÊÔ¶þ·Ö²éÕÒ***********" << endl;
	test_search();

	cout << "**********²âÊÔDijkstraËã·¨******" << endl;
	test_dijkstra();

	cout << "*********²âÊÔµÝ¹éËã·¨************" << endl;
	test_recursion();

	getchar();
	return 0;
}