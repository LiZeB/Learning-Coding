#include "my_sort.h"

/*********运算符重载：针对vector<T>和vector<vector<T>>*********/
template<class T>
ostream & operator <<(ostream &os, vector<T> &v1) {
	/*****************重载了vector的输出*********/
	for (auto const &iter1 : v1) {
		os << iter1 << " ";
	}
	return os;
}

template<class T>
ostream & operator <<(ostream &os, vector<vector<T>> &v1) {
	/*****************重载了vector的输出*********/
	for (auto const &iter1 : v1) {
		for (auto const &iter2 : iter1) {
			os << iter2 << " ";
		}
	}
	return os;
}


template<class T>
void insertI(vector<T> &v1, int gap, int i) {
	int inserted = v1[i];
	int j;
	for (j = i - gap; j >= 0 && inserted < v1[j]; j -= gap) {
		v1[j + gap] = v1[j];
	}
	v1[j + gap] = inserted;
}

template<class T>
void insertSort(vector<T> &v1) {
	/****************************************
	实现了插入排序：算法复杂度是O(N^2)
	*****************************************/
	
	/******如果用STL中的sort来完成前面已经排好序的插入***********/
	//for (int i = 1; i <= v1.size(); i++) { //此处要把i<v1.size改为i<=v1.size,v1.end() == (v1.begin()+v1.size()) 
	//	sort(v1.begin(), v1.begin() + i);
	//}

	/*************自己实现的插入排序************************/
	//vector<int> v2;
	//v2.push_back(v1[0]);
	//for (int i = 1; i < v1.size();i++) {
	//	T temp = v1[i];
	//	//cout << v2 << endl;
	//	for (int j = 0; j < v2.size(); j++) {
	//		if (v1[i] < v2[j]) {
	//			v2.insert(v2.begin() + j, temp);  //这里一定要注意insert函数无法在尾部插入，所以一定要另作处理
	//			break;
	//		}
	//	}
	//	//如果是在尾部插入
	//	if (v1[i] >= v2.back()) {
	//		v2.push_back(temp);
	//	}
	//}
	//v1 = v2;

	/*****比较简洁高效（稍微难以理解）的插入排序写法**********/
	for (int i = 1; i < v1.size();i++) {
		insertI(v1, 1, i);
	}
}

template<class T>
void shellSort(vector<T> &v1) {
	/*********************************
	希尔排序：使用希尔排序的时间复杂度
	完全取决于增量序列的选择；
	使用希尔排序的最坏情形运行时间为O(N^2);
	**********************************/
	int N = v1.size();
	for (int gap = N / 2;gap > 0;gap /= 2) {
		for (int i = gap;i < N;i++) {
			insertI(v1, gap, i);
		}
	}
}