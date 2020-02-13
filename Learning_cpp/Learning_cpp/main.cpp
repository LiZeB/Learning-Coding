#include "characters.h"
#include "container.h"
#include "test_algorithm.h"
#include "my_thread.h"
#include <typeinfo>
#include <limits>

void type_cast();

int main() {
	cout << "***********各个基本内置类型的字节数*****************" << endl;
	cout << "sizeof(short):" << sizeof(short) << endl;
	cout << "sizeof(short *):" << sizeof(short*) << endl;
	cout << "sizeof(unsigned int):" << sizeof(unsigned int) << endl;
	cout << "sizeof(unsigned int *):" << sizeof(unsigned int*) << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(long):" << sizeof(long) << endl;
	cout << "sizeof(long long):" << sizeof(long long) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;
	cout << "sizeof(float):" << sizeof(float) << endl;
	cout << "sizeof(float *):" << sizeof(float *) << endl;
	cout << "INT_MAX=" << INT_MAX << endl;


	int a1[] = { 0, 1, 2, 3, 4, 5};
	char *a2 = "012345";
	cout << "sizeof(a1):" << sizeof(a1) << endl;
	cout << "sizeof(*a1):" << sizeof(*a1) << endl;
	cout << "sizeof(*a2):" << sizeof(*a2) << endl;
	cout << "sizeof(a2):" << sizeof(a2) << endl;

	cout << "********************容器*****************************" << endl;
	cout << "测试vector" << endl;
	test_vector();
	cout << "测试queue" << endl;
	queue<int> q1;
	test_queue(q1, 20);
	cout << "测试map" << endl;
	test_map();
	
	cout << "*************algorithm算法库中的sort******************" << endl;
	cout << "测试sort函数" << endl;
	test_sort();

	cout << "*************常量引用*****************************" << endl;
	int b = 10;
	const int &a = b;
	const int &c = a;
	cout << a <<" "<<c<< endl;

	cout << "*************************string************************" << endl;
	test_string1();
	test_str_functions();

	cout << "********************关联容器、文件流、字符流***********" << endl;
	ifstream input_file("input_file.txt"), map_file("map_file.txt");
	cout << input_file.is_open() << endl;
	words_transform(map_file, input_file);

	cout << "***********************thread 线程类*******************" << endl;
	test_thread2();
	cout << endl;

	cout << "***********************强制类型转换********************" << endl;
	type_cast();

	getchar();
	return 0;
}

void type_cast() {
	int x0 = 65;
	float x1 = static_cast<float>(x0);
	char x2 = static_cast<char>(x0);
	cout << typeid(x1).name() << " " << x1 << endl;
	cout << typeid(x2).name() << " " << x2 << endl;

	const int &x3 = 10;
	int &x4 = const_cast<int&>(x3);
	x4 = 11;
	cout << x3 << " " << x4 << endl;
}