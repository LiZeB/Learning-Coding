#include "forward_list.h"
#include "stack.h"
#include "linkedBinaryTree.h"
#include "hash.h"
#include "graph.h"
#include "my_heap.h"

using namespace std;

int main() {
	cout << "*********��������Ĵ���*************" << endl;
	test_forward_list();

	cout << "***********����ջ�Ĵ���***********" << endl;
	test_stack();
	
	cout << "***************���Զ������Ĵ���******************" << endl;
	test_linkedBinaryTree();

	cout << "****************���Զ���������*******************" << endl;
	test_binarySearchTree();

	cout << "*****************���Թ�ϣ�㷨********************" << endl;
	test_hash();

	cout << "*******************ͼ�Ļ�������******************" << endl;
	test_graph();

	cout << "********************�ѵĻ�������*****************" << endl;
	test_heap();

	getchar();
	return 0;
}

