#include"my_heap.h"

template<class T>
MaxHeap<T>::MaxHeap(int maxHeapSize = 10) {
	if (maxHeapSize <= 0) {
		cout << "maxHeapSize�������0��" << endl;
		exit(0);
	}
	maxSize = maxHeapSize;
	heap = new T[maxSize + 1];
	for (int i = 0; i < (maxSize + 1);i++) {
		heap[i] = NULL;
	}
	currentSize = 0;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::insert(const T& x) {
	if (currentSize == maxSize) {
		cout << "��ǰ���������������ٲ���Ԫ�أ�" << endl;
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

template<class T>
MaxHeap<T>& MaxHeap<T>::deleteMax(T& x) {
	/***************************************************
	��������ɾ��һ��Ԫ������ֻ����ɾ�����ڵ㣨���ֵ����
	Ȼ���ʣ�µ���ȫ��������Ϊ����
	****************************************************/
	if (currentSize == 0) {
		return MaxHeap<T>();
	}

	x = heap[1];
	heap[1] = heap[currentSize];
	heap[currentSize] = NULL;
	currentSize--;
	this->initialize();

	return *this;
}

template<class T>
void MaxHeap<T>::initialize() {
	int j = currentSize / 2;
	while (j >= 1) {
		int i = j;
		while (true) {
			if ((2 * i+1 <= maxSize) && (heap[2 * i+1] != NULL) && (heap[i] < heap[2 * i+1]) &&(heap[2*i]<heap[2*i+1])) {
				T temp = heap[i];
				heap[i] = heap[2 * i+1];
				heap[2 * i+1] = temp;
				i = 2 * i+1;
			}
			else if ((2 * i<= maxSize) && (heap[2 * i] != NULL) && (heap[i] < heap[2 * i])) {
				T temp = heap[i];
				heap[i] = heap[2 * i];
				heap[2 * i] = temp;
				i = 2 * i;
			}
			else{
				break;
			}
		}
		j--;
	}
}

template<class T>
void MaxHeap<T>::output(ostream &out) {
	for (int i = 1;i <= currentSize;i++) {
		out << heap[i] << " ";
	}
	out << endl;
}

template<class T>
void heapSort(vector<T> &v1) {
	MaxHeap<T> h1(v1.size());
	for (auto iter : v1) {
		h1.insert(iter);
	}
	h1.initialize();
	T temp;
	for (int i = v1.size() - 1;i >= 0;i--) {
		h1.deleteMax(temp);
		v1[i] = temp;
	}
}

void test_heap() {
	MaxHeap<int> h1;
	h1.insert(20);
	h1.insert(12);
	h1.insert(35);
	h1.insert(15);
	h1.insert(10);
	h1.insert(80);
	h1.insert(30);
	h1.insert(17);
	h1.insert(2);
	h1.insert(1);

	h1.initialize();
	h1.output(cout);

	int maximum;
	h1.deleteMax(maximum);
	cout << "Maximum:" << maximum<<endl;
	h1.insert(25);
	h1.output(cout);

	cout << "������" << endl;
	vector<int> v1{ 6,3,4,8,9,25,100,78,89,23,0,-1 };
	heapSort(v1);
	for (auto iter : v1) {
		cout << iter << " ";
	}
}