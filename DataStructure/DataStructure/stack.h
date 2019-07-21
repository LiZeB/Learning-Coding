#include <iostream>

using namespace std;

template<class T>
class stack {
public:
	virtual ~stack() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T &theElement) = 0;
};

template<class T>
class linkedStack :public stack<T> {
public:
	linkedStack(int initialCapacity = 100) {
		stackTop = NULL;
		stackSize = 0;
	}
	~linkedStack() {
		while (!this->empty()) {
			this->pop();
		}
	}
	bool empty()const {
		return stackSize == 0;
	}
	int size() const {
		return stackSize;
	}
	T& top() {
		if (this->empty()) {
			exit(0);
		}
		return stackTop->element;
	}
	void pop() {
		if (this->empty()) {
			exit(0);
		}
		chainNode<T> *tempNode = stackTop;
		stackTop = stackTop->next;
		delete tempNode;
		stackSize--;
	}
	void push(const T &theElement) {
		chainNode<T> *tempNode = new chainNode<T>(theElement);
		tempNode->next = stackTop;
		stackTop = tempNode;
		stackSize++;
	}

private:
	chainNode<T> *stackTop; //栈顶指针
	int stackSize;  //栈中元素个数
};

