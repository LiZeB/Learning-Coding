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
map<T, E> & map_sort(map<T, E> &map1) {
	/******************************
	����map������������
	*******************************/
	return map1;
}