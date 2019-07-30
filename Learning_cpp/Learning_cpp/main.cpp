#include<iostream>
#include "characters.h"
#include "container.cpp"

int main()
{
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

	/*************测试队列*****************************/
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	getchar();
	return 0;
}