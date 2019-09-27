#include "my_search.h"

template<class T>
int halfSearch(vector<T> &v1, int start, int end, const T &val) {
	if (start > end) {
		return -1;
	}

	int center = (start + end) / 2;
	if (v1[center] == val) {
		return center;
	}

	if (v1[center] < val) {
		return halfSearch(v1, center + 1, end, val);
	}
	else {
		return halfSearch(v1, start, center - 1, val);
	}
}

template<class T>
int halfSearch(vector<T> &v1, const T &val) {
	/*********************************************
	���ֲ��ң�ʱ�临�Ӷ���O(logN),��v1�д��ڶ����ͬ
	ֵʱ�����ܱ�֤���ҵ����ǵ�һ��Ҫ���ҵ�Ԫ�أ�
	ȡ����v1�ĳ���
	v1:���Ѿ�����õ�����
	**********************************************/
	int N = v1.size();
	if (N == 1) {
		if (v1[0] == val) {
			return 0;
		}
		else {
			return -1;
		}
	}

	int result_index = halfSearch(v1, 0, N - 1, val);

	return result_index;
}

void test_search() {
	vector<int>  v3 = { 1,6,5,4,7,9,23,12,23,34,0 };
	double value = 0;
	int index = halfSearch<int>(v3, value);
	cout << index << endl;
	if (index != -1) {
		cout << v3[index] << endl;
	}
}