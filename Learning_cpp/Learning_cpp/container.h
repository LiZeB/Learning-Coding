#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<vector>
#include<map>
#include<functional>
#include<string>

using namespace std;

//����vector�ĸ��ֳ�ʼ����ʽ
void test_vector();

//����queue��empty()
template<class T>
void test_queue(queue<T> &, T);

//����map������������
template<class T, class E>
map<T, E> map_sort(map<T, E> &);

//��дC++ primer�г��ֵĵ����û�����
void words_transform(ifstream &, ifstream &);