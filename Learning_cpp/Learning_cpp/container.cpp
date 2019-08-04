#include "container.h"

//测试vector的各种初始化方式
void test_vector() {
	/****************************************
	v2(v1), v2 = v1 这两种初始化方式是一样
	的，没有区别；
	******************************************/
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2(v1);    
	v2.push_back(6);
	for (auto &iter : v1) {
		cout << iter << " ";
	}
	for (auto &iter : v2) {
		cout << iter << " ";
	}
	cout << endl;

}

template<class T>
void test_queue(queue<T> &q, T val) {
	/*********************************
	测试了队列的empty操作；
	**********************************/
	q.push(val);
	cout << "队列为空：" << q.empty() << endl;
}

template<class T, class E>
map<T, E>  map_sort(map<T, E> &map1) {
	/******************************
	测试map的内置排序功能
	*******************************/
	struct Point { double x, y; };

	map<T, E> map2(map1.begin(), map1.end());

	return map2;
}