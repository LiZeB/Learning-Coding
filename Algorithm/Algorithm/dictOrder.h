#include<iostream>
#include<vector>

using namespace std;

/*********************第一种：字典序的递归解法***********************/
void print_per(int n, int cur, int* a, vector<int> &v1) {
	if (n == cur)   //递归边界 
		for (int i = 0; i < n; i++) {
			//cout << a[i] << " ";
			v1.push_back(a[i]);
		}
	else {
		for (int i = 1; i <= n; i++) {    //尝试在a[cur]中填各种整数i 
			bool ok = true;
			for (int j = 0; j<cur && ok; j++)
				if (i == a[j])     //i已经在a[0] 到 a[cur]中出现过，则不能再选 
					ok = false;
			if (ok) {
				a[cur] = i;
				print_per(n, cur + 1, a, v1);   //递归调用 
			}
		}
	}
}

void generatePermutation(const int n, const vector<int> find_values) {
	/******************************************
	测试函数，主要针对一次笔试中的题目写的函数；
	n：生成全排列的数字个数，题目中默认从1开始且连续；
	find_values: 保存要查找的排列；
	输入查找排列的索引Q,要输出字典序排列中的倒数第Q个排列
	*******************************************/
	int* a = new int[n];
	vector<int> v1;
	vector<vector<int>> result;
	print_per(n, 0, a, v1);
	//cout << endl;
	vector<int> temp;
	for (int i = 0; i < v1.size(); i++) {
		if ((i % n == 0) && (!temp.empty())) {
			result.push_back(temp);
			temp.clear();
		}
		temp.push_back(v1[i]);
	}
	result.push_back(temp);
	//测试
	cout << "生成的字典序全排列：" << endl;
	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
		}
	}
	cout << endl;
	//在result中寻找与输入排列相同的排列
	int flag;
	for (int i = 0; i < result.size(); i++) {
		if (find_values == result[i]) {
			flag = i;
		}
	}
	//输入排列的索引Q,输出字典序排列中的倒数第Q个排列
	cout << "结果:" << endl;
	for (auto iter2 : result[result.size() - flag - 1]) {
		cout << iter2 << " ";
	}
}


/*****************第二种：字典序的常规解法*********************************/
//https://blog.csdn.net/lijunyan5/article/details/80030697

//交换list[a],list[b] 
void Swap(int list[], int a, int b)
{
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
	return;
}
//将list区间[a,n]之间的数据由小到大排序 
void Sort(int list[], int a, int n)
{
	int temp = 0;
	for (int i = 1; i < n - a; ++i)
		for (int j = a + 1; j < n - 1; ++j)
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
	return;
}
//全排列 
void Prim(int list[], int n)
{
	/********************************
	n：要生成全排列（字典序）的数字个数；
	list: 要生成全排列（字典序）的数字
	*********************************/
	int num = 1, a = 0, b = 0;
	for (int i = n; i > 0; --i)     //计算有多少种情况，就循环多少次 
		num *= i;
	while (num--)
	{
		for (int i = 0; i < n; ++i) //打印情况 
			 cout<<list[i]<<" ";
		cout << endl;

		for (int i = n - 1; i > 0; --i) //从右往左，找出第一个左边小于右边的数，设为list[a] 
			if (list[i - 1] < list[i])
			{
				a = i - 1;
				break;
			}
		for (int j = n - 1; j > a; --j) //从右往左，找出第一个大于list[a]的数，设为list[b] 
			if (list[j] > list[a])
			{
				b = j;
				break;
			}
		Swap(list, a, b);         //交换list[a],list[b] 
		Sort(list, a, n);         //将list[a]后面的数据，由小往大排列 
	}
	return;
}