#include"my_thread.h"

void f1(int n){
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void f2(int& n){
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

class foo{
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

class baz{
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
std::mutex g_num_mutex;

void slow_increment(int id)
{
	for (int i = 0; i < 3; ++i) {
		g_num_mutex.lock();
		++g_num;
		std::cout << id << " => " << g_num << '\n';
		g_num_mutex.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

mutex lock1;    //锁不能作为参数传递

void print(int num) {
	for (int i = 0;i < 3; i++) {
		lock1.lock();
		cout << char(65 + num);
		lock1.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void test_thread(){
	int n = 0;
	foo f;
	baz b;

	/************thread类的构造函数******************/
	std::thread t1; // t1 不是线程
	std::thread t2(f1, n + 1); // 按值传递
	std::thread t3(f2, std::ref(n)); // 按引用传递
	std::thread t4(std::move(t3)); // t4 现在运行 f2() 。 t3 不再是线程
	std::thread t5(&foo::bar, &f); // t5 在对象 f 上运行 foo::bar()
	std::thread t6(b); // t6 在对象 b 上运行 baz::operator()
	t2.join();
	t4.join();
	t5.join();
	t6.join();
	std::cout << "Final value of n is " << n << '\n';
	std::cout << "Final value of foo::n is " << f.n << '\n';

	/***********************给线程加锁*****************/
	std::thread t7(slow_increment, 0);
	std::thread t8(slow_increment, 1);
	t7.join();
	t8.join();

	/*****************多线程笔试题************************/
	/**
	num =3,则输出是ABCABCABC; num=4,则输出是ABCDABCDABCD
	**/
	int num;
	cin >> num;
	thread *t = new thread[num];
	
	for (int j = 0;j < num;j++) {
		t[j] = thread(print, j);
	}
	
	for (int i = 0;i < num;i++) {
		t[i].join();
	}

	getchar();
}
