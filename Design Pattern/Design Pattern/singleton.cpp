#include "singleton.h"

class A {
public:
	A(int a1 = 10):_a1(a1) { cout << "Constructing a A Object!" << _a1 << endl; }
	virtual void func() { cout << "This is A object!" << endl; }
	void test() { func(); }
	void func2() { cout << "Using func2" << endl; func3(); }
protected:
	int _a1;
private:
	virtual void func3() { cout << "Using func3 in A Class" << endl; }
};

class B : public A{
public:
	B() { cout << "Constructing a B Object!" << endl; }
	void func() { cout << "This is B Object!" << _a1 << endl; }
	void func3() { cout << "Using func3 in B Class" << endl; }

	int _b1 = _a1;
};

void test_class_inherited() {
	B *b1 = new B();
	A *a1 = b1;
	a1->test();
	a1->func2();
	cout << endl;
}

class C {
public:
	static int d;   //不包括在类的对象内存中
	char c;
	int a;
	char e;
	float b;
	C() :c(5) {}
	~C() {}
};

class D1 { /*int a = 1;*/ };  //不注释这里是4，注释的话这里是1
class D :public D1 {
public:
	D() {a();}
	D(int b) { cout << "b=" << b; D(); }
	~D() {}
	void a() { cout << "This is a function!" << endl; }
};

void test_class_memory() {
	cout << "普通成员函数的函数表占用内存：" << sizeof(D) << endl;
	cout << "内存对齐：" << "sizeof(C)=" << sizeof(C) << endl;
}

/********单例模式中的饿汉实现方法***************/
class E {
public:
	static E* getInstance() { return instance;}
private:
	E() {}
	static E* instance;
};
E* E::instance = new E();

/********单例模式中的懒汉实现方法*************/
mutex m2;
class F {
public:
	int x1=0;

	static F* getInstance() {
		if (instance == NULL) {
			unique_lock<mutex> my_lock(m2);
			if (instance == NULL)
				instance = new F();
		}
		return instance;
	}
	void func() { cout << x1<<" " << endl; }
private:
	F() { cout << "Constructing a F Object!" << endl; x1 += 1; }
	static F *instance;
};
F* F::instance = NULL;

void create_F() {
	F* f = F::getInstance();
	f->func();
}

void test_singleton() {
	static E* e1 = E::getInstance();
	static E* e2 = E::getInstance();
	cout << (e1 == e2) << endl;
	A* a1 = new A();
	A* a2 = new A();
	cout << (a1 == a2) << endl;

	thread *t2 = new thread[4];
	for (int i = 0; i < 4; i++) {
		t2[i] = thread(create_F);
	}

}