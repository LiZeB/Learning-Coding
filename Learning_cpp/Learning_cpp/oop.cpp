#include "oop.h"

void test_class_inherited() {
	B *b1 = new B();
	B b2 = *b1;
	A *a1 = b1;
	a1->test();
	b1->func();
	cout << endl;
}

void test_class_memory() {
	cout <<"ÄÚ´æ¶ÔÆë£º"<<"sizeof(C):"<< sizeof(C) << endl;
}

void test_class_construction() {
	D d1(5);
}

void test_class_static() {
	E e;
	e.func2();
}