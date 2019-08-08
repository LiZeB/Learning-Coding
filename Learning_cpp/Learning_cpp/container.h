#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<vector>
#include<map>
#include<functional>
#include<string>

using namespace std;

//测试vector的各种初始化方式
void test_vector();

//测试queue的empty()
template<class T>
void test_queue(queue<T> &, T);

//测试map的内置排序功能
template<class T, class E>
map<T, E> map_sort(map<T, E> &);

//重写C++ primer中出现的单词置换程序
void words_transform(ifstream &, ifstream &);