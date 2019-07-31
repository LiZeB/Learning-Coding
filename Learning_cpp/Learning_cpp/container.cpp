#include "container.h"

template<class T>
void test_queue(queue<T> &q, T val) {
	/*********************************
	测试了队列的empty操作；
	**********************************/
	q.push(val);
	cout << "队列为空：" << q.empty() << endl;
}

template<class T, class E>
map<T, E> & map_sort(map<T, E> &map1) {
	/******************************
	测试map的内置排序功能
	*******************************/
	return map1;
}