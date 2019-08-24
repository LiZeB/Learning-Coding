#include<iostream>
#include<ostream>
#include<vector>

using namespace std;

/*****************************************
MaxHeap是一个最大堆：堆的基础是完全二叉树
******************************************/
template<class T>
class MaxHeap {
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() { delete[] heap; }
	int Size() const { return currentSize };
	T Max(){
		if (currentSize == 0) {
			cout << "堆中的元素个数为0！" << endl;
			exit(0);
		}
		else
			return heap[1];
	}
	MaxHeap<T>& insert(const T& x);
	MaxHeap<T>& deleteMax(T& x);    //x接收参数返回的结果

	void initialize();
	void output(ostream&);

private:
	int currentSize, maxSize;
	T *heap;    //元素数组
};

void test_heap();