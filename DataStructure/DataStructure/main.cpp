#include "forward_list.cpp"
#include "stack.h"
#include "linkedBinaryTree.cpp"
#include "hash.h"
#include "graph.h"

using namespace std;

int main() {
	cout << "*********测试链表的代码*************" << endl;
	chain<int> linkList;

	//测试链表的插入
	for (int i = 0; i < 14; i++) {
		linkList.insert(i, 17-i);
	}
	linkList.output(cout);

	//测试链表的拷贝构造函数
	chain<int> linkList2(linkList);
	linkList2.output(cout);

	//测试链表的获取元素的函数
	int a1 = 6;
	int temp = linkList2.get(a1);
	cout <<"按位置"<<a1<<"进行索引:"<< temp << endl;

	//测试根据元素值返回元素值得索引
	int temp2 = linkList2.indexOf(13);
	cout <<"取某一个元素值"<<13<<"的索引：" <<temp2 << endl;

	//测试根据索引删除某一结点
	linkList2.erase(13);
	cout << "删除索引位置" << 13 << "的元素：" << endl;
	linkList2.output(cout);

	//测试用箱子排序算法对链表进行排序
	linkList2.insert(5, 118);
	linkList2.output(cout);
	linkList2.insert(2, 18);
	linkList2.output(cout);
	linkList2.binSort(linkList2.getMax()+1);
	linkList2.output(cout);

	cout << "***********测试栈的代码***********" << endl;
	linkedStack<int> stack1;

	for (int j = 0; j < 10; j++) {
		stack1.push(j);
	}
	stack1.push(100);
	cout << "栈的长度："<<stack1.size()<<endl;
	while (!stack1.empty()) {
		cout << stack1.top() << " ";
		stack1.pop();
	}
	cout << endl;
	
	cout << "***************测试二叉树的代码*****************" << endl;
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

	cout << "****************测试二叉搜索树*******************" << endl;
	binarySearchTree<int, char> y1;
	y1.insert(pair<int, char>(1, 'a'));
	y1.insert(pair<int, char>(6, 'c'));
	y1.insert(pair<int, char>(4, 'b'));
	y1.insert(pair<int, char>(8, 'd'));
	cout << "Tree size is " << y1.size() << endl;
    
	int a_1 = 4;
	y1.erase(a_1);
	cout << "Tree size is " << y1.size() << endl;

	cout << "*****************测试哈希算法************************" << endl;
	//针对<int, int>类型
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
	cout << "哈希表中元素的个数："<<z1.size() << endl;
	int key = 12;
	p = z1.find(key);
	cout << "关键字:"<< key <<p.first << " " << p.second << endl;
	z1.erase(1);
	cout << "删除关键字为1的元素：" << endl;
	z1.output(cout);

	//针对<int, string>类型
	hashChains<int, string> x1;
	x1.insert({ 15, "LiZeBin" });
	x1.insert({ 21, "DongZan" });
	x1.insert({ 24, "LiuYuanDu" });
	cout << "删除之前是：" << endl;
	x1.output(cout);
	cout << "删除之后是：" << endl;
	x1.erase(24);
	x1.output(cout);

	cout << "*******************图的基本操作********************" << endl;
	test_graph();

	getchar();
	return 0;
}