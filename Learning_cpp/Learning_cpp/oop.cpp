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


void create_class() {
	F *f1 = F::getInstance();
	f1->func1();
}

void test_class_Singleton() {
	E *e1 = E::getInstance();
	E *e2 = E::getInstance();
	E *e3 = E::getInstance();
	e1->func1();
	cout << "e1=" << e1 << endl;
	cout << "e2=" << e2 << endl;
	cout << "e3=" << e3 << endl;

	thread *t2 = new thread[4];
	for (int i = 0; i < 4;i++) {
		t2[i] = thread(create_class);
	}

	for (int i = 0; i < 4; i++) {
		t2[i].join();
	}
}

void test_class_SimpleFactory() {
	Geometry *g1 = Geometry::getInstance("circle1");
	Geometry *g2 = Geometry::getInstance("square");
	Geometry *g3 = Geometry::getInstance("triangle");
	float area = g2->compute_area();
	cout << area << endl;
}