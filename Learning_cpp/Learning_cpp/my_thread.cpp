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

int g_num = 0;  // Ϊ g_num_mutex ������
mutex g_num_mutex;

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

mutex lock1;    //��������Ϊ��������

void test_thread1(){
	int n = 0;
	foo f;
	baz b;

	/************thread��Ĺ��캯��******************/
	std::thread t1; // t1 �����߳�
	std::thread t2(f1, n + 1); // ��ֵ����
	std::thread t3(f2, std::ref(n)); // �����ô���
	std::thread t4(std::move(t3)); // t4 �������� f2() �� t3 �������߳�
	std::thread t5(&foo::bar, &f); // t5 �ڶ��� f ������ foo::bar()
	std::thread t6(b); // t6 �ڶ��� b ������ baz::operator()
	t2.join();
	t4.join();
	t5.join();
	t6.join();
	std::cout << "Final value of n is " << n << '\n';
	std::cout << "Final value of foo::n is " << f.n << '\n';

	/***********************���̼߳���*****************/
	std::thread t7(slow_increment, 0);
	std::thread t8(slow_increment, 1);
	t7.join();
	t8.join();
}

mutex m1;
int input_num = 0;
condition_variable cv;

void print(int number, int num){
	for (int i = 0; i < 3;i++) {
		unique_lock<mutex> mlock(m1);
		cv.wait(mlock, [&] {return number == input_num;});
		cout << (char)(65 + number);
		input_num++;
		input_num = input_num % num;
		mlock.unlock();
		cv.notify_all();
	}
}

void print1(int number, int num) {
	int count = 0;
	while(1) {
		unique_lock<mutex> mlock(m1);
		if (number == input_num) {
			cout << (char)(65 + number);
			input_num++;
			count++;
			input_num = input_num % num;
		}
		if (count == 3)
			break;
	}
	/*����д����ԭ�����Լ�һ���̻߳�����ִ�кܶ�����������Ĳ��������¸��̹߳��������
	���������д����Ȼ����ȷ��������Ȼ������������������������������
	for(int i=0;i<3;i++){
		unique_lock<mutex> mlock(m1);
		if (number == input_num) {
			cout << (char)(65 + number);
			input_num++;
			count++;
			input_num = input_num % num;
		}
	}
	*/
}

void test_thread2(){
	/*****************���̱߳�����************************/
	/**
	num =3,�������ABCABCABC; num=4,�������ABCDABCDABCD
	**/
	/*****************************************************/
	int num;
	cin >> num;
	thread *t = new thread[num];

	for (int j = 0;j < num;j++) {
		t[j] = thread(print1, j, num);
	}

	for (int i = 0;i < num;i++) {
		t[i].join();
	}

	getchar();
}

void test_thread3() {
	int num = thread::hardware_concurrency();  
	cout << "��ǰ����֧�ֵ��߳���������������"<<num << endl;
}