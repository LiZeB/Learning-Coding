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

void test_queue(queue<int>, int);

template<class T, class E>
void map_erase(map<T, E> & m1);

template<class T>
struct map_sort {
	bool  operator ()(T p1, T p2) {
		/******************************
		排序的比较函数
		*******************************/
		return p1 >= p2;

	}
};

void test_map();

map<string, string> get_map(ifstream &map_file);

void words_transform(ifstream &, ifstream &);
