#include "test_algorithm.h"

void test_sort()
{
    array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
 
    // 用默认的 operator< 排序
    sort(s.begin(), s.end());
    for (auto a : s) {
        cout << a << " ";
    }   
    cout << '\n';
 
    // 用标准库比较函数对象排序
    sort(s.begin(), s.end(), greater<int>());
    for (auto a : s) {
        cout << a << " ";
    }   
    cout << '\n';
 
    // 用自定义函数对象排序
    struct {
        bool operator()(int a, int b) const
        {   
            return a < b;
        }   
    } customLess;
    sort(s.begin(), s.end(), customLess);
    for (auto a : s) {
        cout << a << " ";
    }   
    cout << '\n';
 
    // 用 lambda 表达式排序
    sort(s.begin(), s.end(), [](int a, int b) {
        return b < a;   
    });
    for (auto a : s) {
        cout << a << " ";
    } 
    cout << '\n';
}