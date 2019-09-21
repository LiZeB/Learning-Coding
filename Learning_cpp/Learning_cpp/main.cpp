#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"
#include "my_thread.cpp"
#include "oop.cpp"
#include <typeinfo>

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


	int a1[] = { 0, 1, 2, 3, 4, 5 };
	char *a2 = "012345";
	cout << "sizeof(a1):" << sizeof(a1) << endl;
	cout << "sizeof(*a1):" << sizeof(*a1) << endl;
	cout << "sizeof(*a2):" << sizeof(*a2) << endl;
	cout << "sizeof(a2):" << sizeof(a2) << endl;

	cout << "********************vector***************************" << endl;
	cout << "测试vector" << endl;
	test_vector();

	cout << "*************队列************************************" << endl;
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	cout << "*******************map字典***************************" << endl;
	test_map();
	
	cout << "*************algorithm算法库中的sort******************" << endl;
	cout << "测试sort函数" << endl;
	test_sort();

	cout << "*************测试常量引用*****************************" << endl;
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

	cout << "***********************面向对象属性********************" << endl;
	test_class_inherited();
	test_class_memory();
	test_class_construction();
	test_class_Singleton();
	test_class_SimpleFactory();
	test_class_Factory();

	cout << "***********************强制类型转换********************" << endl;
	int x0 = 65;
	float x1 = static_cast<float>(x0);
	char x2 = static_cast<char>(x0);
	cout << typeid(x1).name()<<" "<<x1<< endl;
	cout << typeid(x2).name()<<" "<<x2<< endl;

	getchar();
	return 0;
}
