#include<iostream>
#include "link_list.cpp"

using namespace std;

int main() {
	chain<int> linkList;

	//测试链表的插入
	for (int i = 0; i < 10; i++) {
		linkList.insert(i, i);
	}
	linkList.insert(0, 5);
	linkList.insert(1, 2);
	linkList.insert(-1, 3);
	linkList.insert(2, 4);
	linkList.output(cout);

	//测试链表的拷贝构造函数
	chain<int> linkList2(linkList);
	linkList2.output(cout);

	//测试链表的获取元素的函数
	int a = 6;
	int temp = linkList2.get(6);
	cout <<"按位置"<<a<<"进行索引:"<< temp << endl;

	//测试根据元素值返回元素值得索引
	int temp2 = linkList2.indexOf(1);
	cout <<"取某一个元素值"<<temp2<<"得索引：" <<temp2 << endl;

	//测试根据索引删除某一结点
	linkList2.erase(13);
	linkList2.output(cout);
	getchar();
	return 0;
}