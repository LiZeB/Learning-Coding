#include "forward_list.cpp"
#include "stack.h"
#include "linkedBinaryTree.cpp"
#include "hash.h"
#include "graph.h"

using namespace std;

int main() {
	cout << "*********��������Ĵ���*************" << endl;
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

	cout << "***********����ջ�Ĵ���***********" << endl;
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
	
	cout << "***************���Զ������Ĵ���*****************" << endl;
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

	cout << "****************���Զ���������*******************" << endl;
	binarySearchTree<int, char> y1;
	y1.insert(pair<int, char>(1, 'a'));
	y1.insert(pair<int, char>(6, 'c'));
	y1.insert(pair<int, char>(4, 'b'));
	y1.insert(pair<int, char>(8, 'd'));
	cout << "Tree size is " << y1.size() << endl;
    
	int a_1 = 4;
	y1.erase(a_1);
	cout << "Tree size is " << y1.size() << endl;

	cout << "*****************���Թ�ϣ�㷨************************" << endl;
	//���<int, int>����
	hashChains<int, int> z1;
	z1.insert({ 1,1 });

	pair<int, int> p;
	p.first = 2; p.second = 10;
	z1.insert(p);
	p.first = 10; p.second = 50;
	z1.insert(p);
	p.first = 24; p.second = 120;
	z1.insert(p);
	p.first = 32; p.second = 160;
	z1.insert(p);
	p.first = 3; p.second = 15;
	z1.insert(p);
	p.first = 12; p.second = 60;
	z1.insert(p);
	p.first = 23; p.second = 90;
	z1.insert(p);
	p.first = 34; p.second = 120;
	z1.insert(p);
	z1.output(cout);
	cout << "��ϣ����Ԫ�صĸ�����"<<z1.size() << endl;
	int key = 12;
	p = z1.find(key);
	cout << "�ؼ���:"<< key <<p.first << " " << p.second << endl;
	z1.erase(1);
	cout << "ɾ���ؼ���Ϊ1��Ԫ�أ�" << endl;
	z1.output(cout);

	//���<int, string>����
	hashChains<int, string> x1;
	x1.insert({ 15, "LiZeBin" });
	x1.insert({ 21, "DongZan" });
	x1.insert({ 24, "LiuYuanDu" });
	cout << "ɾ��֮ǰ�ǣ�" << endl;
	x1.output(cout);
	cout << "ɾ��֮���ǣ�" << endl;
	x1.erase(24);
	x1.output(cout);

	cout << "*******************ͼ�Ļ�������********************" << endl;
	test_graph();

	getchar();
	return 0;
}