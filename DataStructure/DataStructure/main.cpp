#include "forward_list.h"
#include "stack.h"
#include "linkedBinaryTree.h"
#include "hash.h"
#include "graph.h"
#include "my_heap.h"

using namespace std;

int main() {
	cout << "*********²âÊÔÁ´±íµÄ´úÂë*************" << endl;
	test_forward_list();

	cout << "***********²âÊÔÕ»µÄ´úÂë***********" << endl;
	test_stack();
	
	cout << "***************²âÊÔ¶þ²æÊ÷µÄ´úÂë******************" << endl;
	test_linkedBinaryTree();

	cout << "****************²âÊÔ¶þ²æËÑË÷Ê÷*******************" << endl;
	test_binarySearchTree();

	cout << "*****************²âÊÔ¹þÏ£Ëã·¨********************" << endl;
	test_hash();

	cout << "*******************Í¼µÄ»ù±¾²Ù×÷******************" << endl;
	test_graph();

	cout << "********************¶ÑµÄ»ù±¾²Ù×÷*****************" << endl;
	test_heap();

	getchar();
	return 0;
}

