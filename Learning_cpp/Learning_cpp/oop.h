#include <iostream>
#include <thread>
#include <mutex>
#include <exception>
#include <string>


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

class D1 {};
class D :public D1{
public:
	D() { a(); }
	D(int b) { cout << "b=" << b; D();}
	~D() {}
	void a() { cout << "This is a function!" << endl; }
};

void func3() { cout << "This is function_3" << endl; }

/********����ģʽ�еĶ���ʵ�ַ���***************/
class E {
public:
	void func1() { func3();}
	static E* getInstance() { return instance; }
private:
	E() {}
	static E *instance;
};

E* E::instance;

/********����ģʽ�е�����ʵ�ַ���*************/
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

/******************�򵥹���ģʽ************************/
class Geometry {
public:
	static Geometry* getInstance(string arg);
public:
	virtual void draw() {}
	virtual void erase() {}
	virtual float compute_area() { return (float)(NULL); }
};

class Circle :public Geometry {
public:
	Circle(float radius=5):radius(radius) { cout << "This is a Circle"<<endl; };
	void draw() { cout << "Drawing a Circle" << endl; }
	void erase() { cout << "Erasing a Circle" << endl; }
	float compute_area() { return 3.14*radius*radius; }
private:
	float radius;
};

class Square :public Geometry {
public:
	Square(float length = 5) :length(length) { cout << "This is a Square" << endl; }
	void draw() { cout << "Drawing a Square" << endl; }
	void erase() { cout << "Easing a Square" << endl; }
	float compute_area() { return length*length; }
private:
	float length;
};

class Triangle :public Geometry {
public:
	Triangle(float length = 5, float height=3) : length(length), height(height) { cout << "This is a Triangle" << endl; }
	void draw() { cout << "Drawing a Triangle" << endl; }
	void erase() { cout << "Easing a Triangle" << endl; }
	float compute_area() { return 0.5*length*height; }
private:
	float length;
	float height;
};

//�Զ����쳣
class UnSupportedShapeException : public exception {
public:
	const char * what() const throw ()
	{
		return "UnSupportedShapeException";
	}
};

Geometry* Geometry::getInstance(string arg) {
	if (arg == "circle") {
		return new Circle();
	}
	else if (arg == "square") {
		return new Square();
	}
	else if (arg == "triangle") {
		return new Triangle();
	}
	else {
		try {
			throw UnSupportedShapeException();   //�쳣�������һ����try...catch��ʽ�����ֻ���쳣����������δ�������
		}
		catch (UnSupportedShapeException &e) {
			cout << e.what() << endl;
		}
	}
}

/*********************��������ģʽ***************************/
class Image{
public:
	Image(int height, int width) :height(height), width(width){}
	virtual void write() { cout << "Writing a Image" << endl; }
public:
	int height, width;
};

class Gif_image :public Image {
public:
	Gif_image(int height = 500, int width = 500) :Image(height, width) {}
	void write() { cout << "Writing a Gif Image" << endl; }
};

class Jpg_image :public Image {
public:
	Jpg_image(int height = 500, int width = 500) :Image(height, width) {}
	void read() { cout << "Reading a Jpg Image" << endl; }
	void write() { cout << "Writing a Jpg Image" << endl; }
};

class Loader {
public:
	Loader() {}
	virtual Image* read() = 0;
};

class Jpg_Loader :public Loader {
public:
	Jpg_Loader(){}
	Image* read() { cout << "Reading a Jpg Image" << endl; Jpg_image *result = new Jpg_image(); return result; }
};

class Gif_Loader :public Loader {
public:
	Gif_Loader(){}
	Image* read() { cout << "Reading a Gif Image" << endl; Gif_image *result = new Gif_image(); return result; }
};

/****************���󹤳�ģʽ**********************/
/**
Sunny�����˾���Ƴ�һ���µ��ֻ���Ϸ�����������ܹ�֧��Symbian��Android��Windows Mobile�ȶ�������ֻ�����ϵͳƽ̨��
��Բ�ͬ���ֻ�����ϵͳ������Ϸ����ṩ�˲�ͬ����Ϸ��������(OperationController)�����Ϸ�������(InterfaceController)�࣬
���ṩ��Ӧ�Ĺ���������װ��Щ��ĳ�ʼ�����̡����Ҫ����нϺõ���չ����֧���µĲ���ϵͳƽ̨��
Ϊ���������������Բ��ó��󹤳�ģʽ���������ơ�
**/
class OperationControler {
public:
	OperationControler() { cout << "This is a OperationControler base class!" << endl; }
};

class Symbian_OperationControler :public OperationControler {
public:
	Symbian_OperationControler() { cout << "This is a Symbian_OperationControler class!" << endl; }
};

class Android_OperationControler :public OperationControler {
public:
	Android_OperationControler() { cout << "This is a Android_OperationControler class!" << endl; }
};

class WindowsMobile_OperationControler :public OperationControler {
public:
	WindowsMobile_OperationControler() { cout << "This is a WindowsMobile_OperationControler class!" << endl; }
};

class InterfaceControler {
public:
	InterfaceControler() { cout << "This is a InterfaceControler base class!" << endl; }
};

class Symbian_InterfaceControler :public InterfaceControler {
public:
	Symbian_InterfaceControler() { cout << "This is a Symbian_InterfaceControler class!" << endl; }
};

class Android_InterfaceControler :public InterfaceControler {
public:
	Android_InterfaceControler() { cout << "This is a Android_InterfaceControler class!" << endl; }
};

class WindowsMobile_InterfaceControler :public InterfaceControler {
public:
	WindowsMobile_InterfaceControler() { cout << "This is a WindowsMobile_InterfaceControler class!" << endl; }
};

class factory {
public:
	factory() { cout << "This is factory base class!" << endl; }
	virtual OperationControler* createOperationControler() = 0;
	virtual InterfaceControler* createInterfaceControler() = 0;
};

class Symbian_factory :public factory {
public:
	Symbian_factory() { cout << "This is Symbian Factory class!" << endl; }
	OperationControler* createOperationControler() { 
		cout << "creating a Symbian OperationControler" << endl; 
		return new Symbian_OperationControler();
	}
	InterfaceControler* createInterfaceControler() { 
		cout << "creating a Symbian OperationControler" << endl; 
		return new Symbian_InterfaceControler();
	}
};

class Android_factory :public factory {
public:
	Android_factory() { cout << "This is Android Factory class!" << endl; }
	OperationControler* createOperationControler() { 
		cout << "creating a Android OperationControler" << endl; 
		return new Android_OperationControler();
	}
	InterfaceControler* createInterfaceControler() { 
		cout << "creating a Android OperationControler" << endl; 
		return new Android_InterfaceControler();
	}
};

class WindowsMobile_factory :public factory {
public:
	WindowsMobile_factory() { cout << "This is WindowsMobile Factory class!" << endl; }
	OperationControler* createOperationControler() { 
		cout << "creating a WindowsMobile OperationControler" << endl;
		return new WindowsMobile_OperationControler();
	}
	InterfaceControler* createInterfaceControler() { 
		cout << "creating a WindowsMobile OperationControler" << endl; 
		return new WindowsMobile_InterfaceControler();
	}
};













