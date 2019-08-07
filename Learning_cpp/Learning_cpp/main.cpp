#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"

int main() {
	/***********测试splict_string的代码************/
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

	/***********测试各个基本内置类型的字节数*********/
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;

	/********************测试vector*********************/
	cout << "测试vector" << endl;
	test_vector();

	/*************测试队列*****************************/
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	/*******************测试map字典********************/
	map<int, char*> map1;
	map1[3] = "c";
	map1[2] = "b";
	map1[1] = "a";

	map1 = map_sort(map1);
	cout << "遍历字典" << endl;
	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		cout << iter->first << iter->second << endl;
	}
	
	/*************测试algorithm算法库中的sort******************/
	cout << "测试sort函数" << endl;
	test_sort();

	int b = 10;
	const int &a = b;
	cout << a << endl;

	getchar();
	return 0;
}


