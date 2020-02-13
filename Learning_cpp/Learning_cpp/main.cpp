#include "characters.h"
#include "container.h"
#include "test_algorithm.h"
#include "my_thread.h"
#include <typeinfo>
#include <limits>

void type_cast();

int main() {
	cout << "***********���������������͵��ֽ���*****************" << endl;
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

	cout << "********************����*****************************" << endl;
	cout << "����vector" << endl;
	test_vector();
	cout << "����queue" << endl;
	queue<int> q1;
	test_queue(q1, 20);
	cout << "����map" << endl;
	test_map();
	
	cout << "*************algorithm�㷨���е�sort******************" << endl;
	cout << "����sort����" << endl;
	test_sort();

	cout << "*************��������*****************************" << endl;
	int b = 10;
	const int &a = b;
	const int &c = a;
	cout << a <<" "<<c<< endl;

	cout << "*************************string************************" << endl;
	test_string1();
	test_str_functions();

	cout << "********************�����������ļ������ַ���***********" << endl;
	ifstream input_file("input_file.txt"), map_file("map_file.txt");
	cout << input_file.is_open() << endl;
	words_transform(map_file, input_file);

	cout << "***********************thread �߳���*******************" << endl;
	test_thread2();
	cout << endl;

	cout << "***********************ǿ������ת��********************" << endl;
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