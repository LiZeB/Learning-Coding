#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<functional>

using namespace std;

//测试queue的empty()
template<class T>
void test_queue(queue<T> &, T);

//测试map的内置排序功能
template<class T, class E>
map<T, E> & map_sort(map<T, E> &);