#include "forward_list.cpp"
#include "stack.h"
#include "linkedBinaryTree.cpp"
#include "hash.h"

using namespace std;

int main() {
	///*********��������Ĵ���**********/
	//chain<int> linkList;

	////��������Ĳ���
	//for (int i = 0; i < 14; i++) {
	//	linkList.insert(i, 17-i);
	//}
	//linkList.output(cout);

	////��������Ŀ������캯��
	//chain<int> linkList2(linkList);
	//linkList2.output(cout);

	////��������Ļ�ȡԪ�صĺ���
	//int a1 = 6;
	//int temp = linkList2.get(a1);
	//cout <<"��λ��"<<a1<<"��������:"<< temp << endl;

	////���Ը���Ԫ��ֵ����Ԫ��ֵ������
	//int temp2 = linkList2.indexOf(13);
	//cout <<"ȡĳһ��Ԫ��ֵ"<<13<<"��������" <<temp2 << endl;

	////���Ը�������ɾ��ĳһ���
	//linkList2.erase(13);
	//cout << "ɾ������λ��" << 13 << "��Ԫ�أ�" << endl;
	//linkList2.output(cout);

	////���������������㷨�������������
	//linkList2.insert(5, 118);
	//linkList2.output(cout);
	//linkList2.insert(2, 18);
	//linkList2.output(cout);
	//linkList2.binSort(linkList2.getMax()+1);
	//linkList2.output(cout);

	///***********����ջ�Ĵ���***********/
	//linkedStack<int> stack1;

	//for (int j = 0; j < 10; j++) {
	//	stack1.push(j);
	//}
	//stack1.push(100);
	//cout << "ջ�ĳ��ȣ�"<<stack1.size()<<endl;
	//while (!stack1.empty()) {
	//	cout << stack1.top() << " ";
	//	stack1.pop();
	//}
	//cout << endl;
	//
	///***************���Զ������Ĵ���*****************/
	//linkedBinaryTree<int> a, x, y, z;
	//y.makeTree(1, a, a);
	//z.makeTree(2, a, a);
	//x.makeTree(3, y, z);
	//y.makeTree(4, x, a);
	//cout << "Number of nodes = ";
	//cout << y.size() << endl;
	//cout << "height = ";
	//cout << y.height() << endl;
	//cout << "Preorder sequence is ";
	//y.preOrderOutput();
	//cout << "Inorder sequence is ";
	//y.inOrderOutput();
	//cout << "Postorder sequence is ";
	//y.postOrderOutput();
	//cout << "Levelorder sequence is ";
	//y.levelOrderOutput();

	///****************���Զ���������*******************/
	//binarySearchTree<int, char> y1;
	//y1.insert(pair<int, char>(1, 'a'));
	//y1.insert(pair<int, char>(6, 'c'));
	//y1.insert(pair<int, char>(4, 'b'));
	//y1.insert(pair<int, char>(8, 'd'));
	//cout << "Tree size is " << y1.size() << endl;
 //   
	//int a_1 = 4;
	//y1.erase(a_1);
	//cout << "Tree size is " << y1.size() << endl;

	/*****************���Թ�ϣ�㷨************************/
	//���<int, int>����
	hashChains<int, int> z;
	z.insert({ 1,1 });

	pair<int, int> p;
	p.first = 2; p.second = 10;
	z.insert(p);
	p.first = 10; p.second = 50;
	z.insert(p);
	p.first = 24; p.second = 120;
	z.insert(p);
	p.first = 32; p.second = 160;
	z.insert(p);
	p.first = 3; p.second = 15;
	z.insert(p);
	p.first = 12; p.second = 60;
	z.insert(p);
	p.first = 23; p.second = 90;
	z.insert(p);
	p.first = 34; p.second = 120;
	z.insert(p);
	z.output(cout);
	cout << "��ϣ����Ԫ�صĸ�����"<<z.size() << endl;
	int key = 12;
	p = z.find(key);
	cout << "�ؼ���:"<< key <<p.first << " " << p.second << endl;
	z.erase(1);
	cout << "ɾ���ؼ���Ϊ1��Ԫ�أ�" << endl;
	z.output(cout);

	//���<int, string>����
	hashChains<int, string> x;
	x.insert({ 15, "LiZeBin" });
	x.insert({ 21, "DongZan" });
	x.insert({ 24, "LiuYuanDu" });
	cout << "ɾ��֮ǰ�ǣ�" << endl;
	x.output(cout);
	cout << "ɾ��֮���ǣ�" << endl;
	x.erase(24);
	x.output(cout);

	getchar();
	return 0;
}