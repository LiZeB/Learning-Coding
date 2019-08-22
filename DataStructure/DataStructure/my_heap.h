#include<iostream>

using namespace std;

template<class T>
class MaxHeap {
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() { delete[] heap; }
	int Size() const { return currentSize };
	T Max(){
		if (currentSize == 0) {
			cout << "���е�Ԫ�ظ���Ϊ0��" << endl;
			exit(0);
		}
		else
			return heap[1];
	}
	MaxHeap<T>& insert(const T& x);
	MaxHeap<T>& deleteMax(T& x);
	void initialize(T a[], int size, int ArraySize);

private:
	int currentSize, maxSize;
	T *heap;    //Ԫ������
};

void test_heap();