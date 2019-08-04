#include<iostream>
#include<vector>

using namespace std;

/*********************��һ�֣��ֵ���ĵݹ�ⷨ***********************/
void print_per(int n, int cur, int* a, vector<int> &v1) {
	if (n == cur)   //�ݹ�߽� 
		for (int i = 0; i < n; i++) {
			//cout << a[i] << " ";
			v1.push_back(a[i]);
		}
	else {
		for (int i = 1; i <= n; i++) {    //������a[cur]�����������i 
			bool ok = true;
			for (int j = 0; j<cur && ok; j++)
				if (i == a[j])     //i�Ѿ���a[0] �� a[cur]�г��ֹ���������ѡ 
					ok = false;
			if (ok) {
				a[cur] = i;
				print_per(n, cur + 1, a, v1);   //�ݹ���� 
			}
		}
	}
}

void generatePermutation(const int n, const vector<int> find_values) {
	/******************************************
	���Ժ�������Ҫ���һ�α����е���Ŀд�ĺ�����
	n������ȫ���е����ָ�������Ŀ��Ĭ�ϴ�1��ʼ��������
	find_values: ����Ҫ���ҵ����У�
	����������е�����Q,Ҫ����ֵ��������еĵ�����Q������
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
	//����
	cout << "���ɵ��ֵ���ȫ���У�" << endl;
	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
		}
	}
	cout << endl;
	//��result��Ѱ��������������ͬ������
	int flag;
	for (int i = 0; i < result.size(); i++) {
		if (find_values == result[i]) {
			flag = i;
		}
	}
	//�������е�����Q,����ֵ��������еĵ�����Q������
	cout << "���:" << endl;
	for (auto iter2 : result[result.size() - flag - 1]) {
		cout << iter2 << " ";
	}
}


/*****************�ڶ��֣��ֵ���ĳ���ⷨ*********************************/
//https://blog.csdn.net/lijunyan5/article/details/80030697

//����list[a],list[b] 
void Swap(int list[], int a, int b)
{
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
	return;
}
//��list����[a,n]֮���������С�������� 
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
//ȫ���� 
void Prim(int list[], int n)
{
	/********************************
	n��Ҫ����ȫ���У��ֵ��򣩵����ָ�����
	list: Ҫ����ȫ���У��ֵ��򣩵�����
	*********************************/
	int num = 1, a = 0, b = 0;
	for (int i = n; i > 0; --i)     //�����ж������������ѭ�����ٴ� 
		num *= i;
	while (num--)
	{
		for (int i = 0; i < n; ++i) //��ӡ��� 
			 cout<<list[i]<<" ";
		cout << endl;

		for (int i = n - 1; i > 0; --i) //���������ҳ���һ�����С���ұߵ�������Ϊlist[a] 
			if (list[i - 1] < list[i])
			{
				a = i - 1;
				break;
			}
		for (int j = n - 1; j > a; --j) //���������ҳ���һ������list[a]��������Ϊlist[b] 
			if (list[j] > list[a])
			{
				b = j;
				break;
			}
		Swap(list, a, b);         //����list[a],list[b] 
		Sort(list, a, n);         //��list[a]��������ݣ���С�������� 
	}
	return;
}