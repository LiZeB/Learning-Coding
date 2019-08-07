#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"

int main() {
	/***********����splict_string�Ĵ���************/
	   char *input = "Hello World, my name is LiZeBin";     
	   vector<string> output;
	   output = splict_string(input, ",");
	   cout<<"original input:"<<input<<endl;  
	cout << ", as separator:" << endl;
	for (auto iter = output.begin();iter != output.end(); iter++) {
		cout << (*iter) << endl;
	}

	cout << "whitespace as separator:" << endl;
	output = splict_string(input, " ");
	for(decltype(output.size()) i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	cout << "m as separator:" << endl;
	output = splict_string(input, "m");
	for (auto i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	/***********���Ը��������������͵��ֽ���*********/
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;

	/********************����vector*********************/
	cout << "����vector" << endl;
	test_vector();

	/*************���Զ���*****************************/
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	/*******************����map�ֵ�********************/
	map<int, char*> map1;
	map1[3] = "c";
	map1[2] = "b";
	map1[1] = "a";

	map1 = map_sort(map1);
	cout << "�����ֵ�" << endl;
	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		cout << iter->first << iter->second << endl;
	}
	
	/*************����algorithm�㷨���е�sort******************/
	cout << "����sort����" << endl;
	test_sort();

	int b = 10;
	const int &a = b;
	cout << a << endl;

	getchar();
	return 0;
}


