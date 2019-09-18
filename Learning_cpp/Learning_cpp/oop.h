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

/******************简单工厂模式************************/
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

//自定义异常
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
			throw UnSupportedShapeException();   //异常处理代码一定是try...catch形式，如果只抛异常不处理会产生未定义错误
		}
		catch (UnSupportedShapeException &e) {
			cout << e.what() << endl;
		}
	}
}

/*********************工厂方法模式***************************/
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
	virtual Image* read() { cout << "Reading a Image" << endl; return (Image*)(NULL); }
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













