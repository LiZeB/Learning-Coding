#include "oop.h"

void test_class_inherited() {
	B *b1 = new B();
	B b2 = *b1;
	A *a1 = b1;
	b1->func();
	cout << endl;
}