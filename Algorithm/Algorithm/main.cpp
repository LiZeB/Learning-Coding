#include "dictOrder.h"
#include "my_sort.cpp"

int main()
{
	/***********²âÊÔ×ÖµäĞò**********/
	/*int list[] = { 2,3,4,5 };
	Prim(list, 4);

	generatePermutation(3, vector<int>{1, 2, 3});*/

	/************²âÊÔ²åÈëÅÅĞò**********/
	vector<int> v1{ 6,2,4,5,1,2,3,0,7,4,5,9,10, -90, 100};
	insertSort(v1);
	vector<vector<int>> v3{ v1 };  //²âÊÔÔËËã·ûÖØÔØ
	cout << v3 << endl;

	/*************²âÊÔÏ£¶ûÅÅĞò***********/
	/*vector<int> v1{ 6,2,4,5,1,2,3,0,7,4,5,9,10 };
	cout << "Ô­ĞòÁĞ£º" << v1 << endl;
	shellSort(v1);
	cout << v1 << endl;*/

	getchar();
	return 0;
}