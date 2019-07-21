#include "forward_list.cpp"
#include "stack.h"

using namespace std;

int main() {
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
	int a = 6;
	int temp = linkList2.get(6);
	cout <<"按位置"<<a<<"进行索引:"<< temp << endl;

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

	/***********测试栈的代码***********/
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

	getchar();
	return 0;
}