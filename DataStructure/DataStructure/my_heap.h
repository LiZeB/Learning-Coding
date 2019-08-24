#include<iostream>
#include<ostream>
#include<vector>

using namespace std;

/*****************************************
MaxHeap��һ�����ѣ��ѵĻ�������ȫ������
******************************************/
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
	MaxHeap<T>& deleteMax(T& x);    //x���ղ������صĽ��

	void initialize();
	void output(ostream&);

private:
	int currentSize, maxSize;
	T *heap;    //Ԫ������
};

void test_heap();