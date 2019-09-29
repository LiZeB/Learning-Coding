#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

void f1(int n);
void f2(int& n);

class foo {
public:
	void bar()
	{
		for (int i = 0; i < 5; ++i) {
			std::cout << "Thread 3 executing\n";
			++n;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	int n = 0;
};

class baz {
public:
	void operator()()
	{
		for (int i = 0; i < 5; ++i) {
			std::cout << "Thread 4 executing\n";
			++n;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	int n = 0;
};

int g_num = 0;  // 为 g_num_mutex 所保护
mutex g_num_mutex;
mutex lock1;    //锁不能作为参数传递

void slow_increment(int id);

void test_thread1();

mutex m1;
int input_num = 0;
condition_variable cv;

void print(int number, int num);
void print1(int number, int num);
void test_thread2();
void test_thread3();
