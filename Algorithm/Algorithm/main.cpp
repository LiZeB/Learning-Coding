#include "dictOrder.h"
#include "my_sort.cpp"
#include "my_search.cpp"

int main()
{
	/***********�����ֵ���**********/
	/*int list[] = { 2,3,4,5 };
	Prim(list, 4);

	generatePermutation(3, vector<int>{1, 2, 3});*/

	/************���Բ�������**********/
	//vector<int> v1{ 6,2,4,5,1,2,3,0,7,4,5,9,10, -90, 100};
	//insertSort(v1);
	//vector<vector<int>> v3{ v1 };  //�������������
	//cout << v3 << endl;

	/*************����ϣ������***********/
	/*vector<int> v1{ 6,2,4,5,1,2,3,0,7,4,5,9,10 };
	cout << "ԭ���У�" << v1 << endl;
	shellSort(v1);
	cout << v1 << endl;*/

	/*************����ð������***********/
	/*vector<double> v1{ 6,2,4,5,1,2,3,0,7,4,5,9,10,34,25,-90.0, 100.0 };
	bubbleSort(v1);
	cout << v1 << endl;*/

	/***********���Թ鲢����*************/
	/*vector<double> v1{1,3,4,40,56,89,-100,5,6,7,8,1000};
	mergeSort(v1);
	cout << v1 << endl;*/

	/************���Կ�������****************/
	vector<double> v1{1,2,3,3,2,-90,-90,6,2,4,5,1,2,3,0,7,4,5,9,10,34,25,-90.0, 100.0,1,3,4,40,56,89,-100,5,6,7,8,100};
	vector<double> v2{9,8,7,6,5,4,3,2,1,0};
	vector<double> v3{ 2 };
	quickSort(v2);
	cout << v2 << endl;

	/***************���Զ��ֲ���**************/
	double value = 0;
	int index = halfSearch(v3, value);
	cout << index <<endl;
	if (index != -1) {
		cout << v2[index] << endl;
	}

	getchar();
	return 0;
}