#include"my_heap.h"

template<class T>
MaxHeap<T>::MaxHeap(int maxHeapSize = 10) {
	if (maxHeapSize <= 0) {
		cout << "maxHeapSize必须大于0！" << endl;
		exit(0);
	}
	maxSize = maxHeapSize;
	heap = new T[maxSize + 1];
	currentSize = 0;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::insert(const T& x) {
	if (currentSize == maxSize) {
		cout << "当前最大堆已满，不能再插入元素！" << endl;
		exit(0);
	}
	heap[currentSize + 1] = x;
	currentSize += 1;

	int index_pre = currentSize / 2, index_cur = currentSize;
	while (index_pre >= 1) {
		if (heap[index_pre] < heap[index_cur]) {
			T temp = heap[index_pre];
			heap[index_pre] = heap[index_cur];
			heap[index_cur] = temp;
		}
		index_cur = index_pre;
		index_pre = index_pre / 2;
	}

	return *this;
}

void test_heap() {
	MaxHeap<int> h1;
	h1.insert(10);
	h1.insert(8);
	h1.insert(6);
}