#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<functional>

using namespace std;

//����vector�ĸ��ֳ�ʼ����ʽ
void test_vector();

//����queue��empty()
template<class T>
void test_queue(queue<T> &, T);

//����map������������
template<class T, class E>
map<T, E> map_sort(map<T, E> &);