#include "container.h"

//����vector�ĸ��ֳ�ʼ����ʽ
void test_vector() {
	/****************************************
	v2(v1), v2 = v1 �����ֳ�ʼ����ʽ��һ��
	�ģ�û������
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