#include "forward_list.cpp"
#include "stack.h"
#include "linkedBinaryTree.cpp"

using namespace std;

int main() {
	/*********��������Ĵ���**********/
	chain<int> linkList;

	//��������Ĳ���
	for (int i = 0; i < 14; i++) {
		linkList.insert(i, 17-i);
	}
	linkList.output(cout);

	//��������Ŀ������캯��
	chain<int> linkList2(linkList);
	linkList2.output(cout);

	//��������Ļ�ȡԪ�صĺ���
	int a1 = 6;
	int temp = linkList2.get(a1);
	cout <<"��λ��"<<a1<<"��������:"<< temp << endl;

	//���Ը���Ԫ��ֵ����Ԫ��ֵ������
	int temp2 = linkList2.indexOf(13);
	cout <<"ȡĳһ��Ԫ��ֵ"<<13<<"��������" <<temp2 << endl;

	//���Ը�������ɾ��ĳһ���
	linkList2.erase(13);
	cout << "ɾ������λ��" << 13 << "��Ԫ�أ�" << endl;
	linkList2.output(cout);

	//���������������㷨�������������
	linkList2.insert(5, 118);
	linkList2.output(cout);
	linkList2.insert(2, 18);
	linkList2.output(cout);
	linkList2.binSort(linkList2.getMax()+1);
	linkList2.output(cout);

	/***********����ջ�Ĵ���***********/
	linkedStack<int> stack1;

	for (int j = 0; j < 10; j++) {
		stack1.push(j);
	}
	stack1.push(100);
	cout << "ջ�ĳ��ȣ�"<<stack1.size()<<endl;
	while (!stack1.empty()) {
		cout << stack1.top() << " ";
		stack1.pop();
	}
	cout << endl;
	
	/***************���Զ������Ĵ���*****************/
	linkedBinaryTree<int> a, x, y, z;
	y.makeTree(1, a, a);
	z.makeTree(2, a, a);
	x.makeTree(3, y, z);
	y.makeTree(4, x, a);
	cout << "Number of nodes = ";
	cout << y.size() << endl;
	cout << "height = ";
	cout << y.height() << endl;
	cout << "Preorder sequence is ";
	y.preOrderOutput();
	cout << "Inorder sequence is ";
	y.inOrderOutput();
	cout << "Postorder sequence is ";
	y.postOrderOutput();
	cout << "Levelorder sequence is ";
	y.levelOrderOutput();

	//y.removeLeftSubtree(); ��������ȷ����

	getchar();
	return 0;
}