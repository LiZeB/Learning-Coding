#include "my_sort.h"

/*********��������أ����vector<T>��vector<vector<T>>*********/
template<class T>
ostream & operator <<(ostream &os, vector<T> &v1) {
	/*****************������vector�����*********/
	for (auto const &iter1 : v1) {
		os << iter1 << " ";
	}
	return os;
}

template<class T>
ostream & operator <<(ostream &os, vector<vector<T>> &v1) {
	/*****************������vector�����*********/
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
	ʵ���˲��������㷨���Ӷ���O(N^2)
	*****************************************/
	
	/******�����STL�е�sort�����ǰ���Ѿ��ź���Ĳ���***********/
	//for (int i = 1; i <= v1.size(); i++) { //�˴�Ҫ��i<v1.size��Ϊi<=v1.size,v1.end() == (v1.begin()+v1.size()) 
	//	sort(v1.begin(), v1.begin() + i);
	//}

	/*************�Լ�ʵ�ֵĲ�������************************/
	//vector<int> v2;
	//v2.push_back(v1[0]);
	//for (int i = 1; i < v1.size();i++) {
	//	T temp = v1[i];
	//	//cout << v2 << endl;
	//	for (int j = 0; j < v2.size(); j++) {
	//		if (v1[i] < v2[j]) {
	//			v2.insert(v2.begin() + j, temp);  //����һ��Ҫע��insert�����޷���β�����룬����һ��Ҫ��������
	//			break;
	//		}
	//	}
	//	//�������β������
	//	if (v1[i] >= v2.back()) {
	//		v2.push_back(temp);
	//	}
	//}
	//v1 = v2;

	/*****�Ƚϼ���Ч����΢������⣩�Ĳ�������д��**********/
	for (int i = 1; i < v1.size();i++) {
		insertI(v1, 1, i);
	}
}

template<class T>
void shellSort(vector<T> &v1) {
	/*********************************
	ϣ������ʹ��ϣ�������ʱ�临�Ӷ�
	��ȫȡ�����������е�ѡ��
	ʹ��ϣ����������������ʱ��ΪO(N^2);
	**********************************/
	int N = v1.size();
	for (int gap = N / 2;gap > 0;gap /= 2) {
		for (int i = gap;i < N;i++) {
			insertI(v1, gap, i);
		}
	}
}

template<class T>
void bubbleSort(vector<T> &v1) {
	/*****************************************
	ð�������㷨���Ӷ���O(N^2)
	******************************************/
	T temp;
	for (int i = 0; i < v1.size();i++) {
		for (int j = 1;j < v1.size() - i;j++) {
			if (v1[j] < v1[j - 1]) {
				temp = v1[j];
				v1[j] = v1[j - 1];
				v1[j - 1] = temp;
			}
		}
	}
}

template<class T>
vector<T> merge(vector<T> &v1, vector<T> &v2) {
	/******************************************
	�ϲ�������������
	*******************************************/
	int n1 = 0, n2 = 0, N1 = v1.size(), N2 = v2.size();
	vector<T> result;
	while (n1 < N1 && n2 < N2) {
		if (v1[n1] < v2[n2]) {
			result.push_back(v1[n1]);
			n1++;
		}
		else {
			result.push_back(v2[n2]);
			n2++;
		}
	}
	if (n1 == N1) {
		for (int i = n2;i < N2;i++) {
			result.push_back(v2[i]);
		}
	}
	else {
		for (int j = n1;j < N1; j++) {
			result.push_back(v1[j]);
		}
	}

	return result;
}

template<class T>
vector<T> mergeSort(vector<T> &v1, int start, int end) {
	if (end == start) {
		return vector<T>{v1[end]};
	}
	int center = (start + end) / 2;
	vector<T> v2 = mergeSort(v1, start, center);    //��һ�α�д��ʱ��ϸ�ģ�д�ɣ�vector<T> v2 = mergeSort(v1, start, end/2);
	vector<T> v3 = mergeSort(v1, center + 1, end);   // ����д����vector<T> v3 = mergeSort(v1, end/2+1, end)
	
	return merge(v2, v3);
}

template<class T>
void mergeSort(vector<T> &v1) {
	/**************************************
	�鲢�����㷨���Ӷ���O(NlogN),ͨ��һ���ݹ鷽�̿�����ã�T(N) = T(N/2)+N;
	***************************************/
	int N = v1.size();
	vector<T> v2 = mergeSort(v1, 0, N-1);
	v1 = v2;
}
