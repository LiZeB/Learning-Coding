#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <utility>


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

/********单例模式中的饿汉实现方法***************/
class E {
public:
	void func1() { func3();}
	static E* getInstance() { return instance; }
private:
	E() {}
	static E *instance;
};

E* E::instance = new E();

/********单例模式中的懒汉实现方法*************/
mutex m2;
class F {
public:
	void func1() { func3(); }
	static F* getInstance() {
		if (instance == NULL) {
			unique_lock<mutex> my_lock(m2);
			if(instance==NULL)
				instance = new F();
		}
		cout << instance << endl;
		return instance;
	}
private:
	F() {}
	static F *instance;
};

F* F::instance = NULL;