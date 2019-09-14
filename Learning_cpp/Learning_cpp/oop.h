#include <iostream>

using namespace std;

class A {
public:
	A(int a1 = 10) :_a1(a1) { cout << _a1 << endl;cout << "Constructing a A Object!" << endl; }
	virtual void func() { cout << "This is A object!" << endl; }
	
	void test() { func(); }
protected:
	int _a1;
	void func2() { cout << "Using func2" << endl; }
};

class B : public A {
public:
	B() { cout << "Constructing a B Object!"<<endl; }
	void func() { cout << "This is B Object!" << endl; cout << _a1 << endl; }
public:
	int _b1 = _a1;
};

class C {
public:
	static int d;
	char c;
	int a;
	char e;
	float b;
	C();
	~C();
};

class D {
public:
	D() { a(); }
	D(int b) { cout << "b=" << b; D();}
	~D() {}
	void a() { cout << "This is a function!" << endl; }
};

void func3() { cout << "This is function_3" << endl; }

class E {
public:
	E() { cout << "This is construction function."<<endl; }
	static void func1() { E();func3();}
	void func2() { cout << "This is function_2."; func1(); }
};
