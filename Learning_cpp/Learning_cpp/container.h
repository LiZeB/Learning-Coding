#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<vector>
#include<map>
#include<functional>
#include<string>
#include<utility>

using namespace std;

void test_vector();

template<class T>
void test_queue(queue<T> &, T);

void test_map();

//��дC++ primer�г��ֵĵ����û�����
void words_transform(ifstream &, ifstream &);