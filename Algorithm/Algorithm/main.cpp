#include "dictOrder.h"
#include "my_sort.cpp"

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
	vector<double> v2{ -100,-90,-90,-90,0,1,1,1,2,2,2,2,3,3,3,3,4,4,4,5,5,5,6,6,7,7,8,9,10,25,34,40,56,89,100,100};
	quickSort(v2);
	cout << v2 << endl;


	getchar();
	return 0;
}