#include "container.h"

template<class T>
void test_queue(queue<T> &q, T val) {
	/*********************************
	�����˶��е�empty������
	**********************************/
	q.push(val);
	cout << "����Ϊ�գ�" << q.empty() << endl;
}

template<class T, class E>
map<T, E>  map_sort(map<T, E> &map1) {
	/******************************
	����map������������
	*******************************/
	struct Point { double x, y; };

	map<T, E> map2(map1.begin(), map1.end());

	return map2;
}