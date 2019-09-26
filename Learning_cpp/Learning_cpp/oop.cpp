#include "oop.h"

void test_class_inherited() {
	B *b1 = new B();
	A *a1 = b1;
	a1->test();

	b1->func2();
	cout << endl;
}

void test_class_memory() {
	cout << "普通成员函数的函数表占用内存：" << sizeof(D) << endl;
	cout <<"内存对齐："<<"sizeof(C):"<< sizeof(C) << endl;
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

void test_class_Factory() {
	Loader *l1 = new Gif_Loader();
	Image *m1 = l1->read();
	Loader *l2 = new Jpg_Loader();
	Image *m2 = l2->read();
	m1->write();
	m2->write();
}

void test_class_AbstractFactory() {
	factory *f = new Android_factory();
	OperationControler *operation = f->createOperationControler();
	InterfaceControler *interface = f->createInterfaceControler();
}