#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"
#include "my_thread.cpp"

int main() {
	cout << "***********splict_string的代码************" << endl;
	char *input = "Hello World, my name is LiZeBin";     
    vector<string> output;
    output = splict(input, ",");
    cout<<"original input:"<<input<<endl;  
	cout << ", as separator:" << endl;
	for (auto iter = output.begin();iter != output.end(); iter++) {
		cout << (*iter) << endl;
	}

	cout << "whitespace as separator:" << endl;
	output = splict(input, " ");
	for(decltype(output.size()) i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	cout << "my as separator:" << endl;
	output = splict(input, "my");
	for (auto i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	cout << "***********各个基本内置类型的字节数*********" << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;

	cout << "********************vector*********************" << endl;
	cout << "测试vector" << endl;
	test_vector();

	cout << "*************队列*****************************" << endl;
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	cout << "*******************map字典********************" << endl;
	map<int, char*> map1;
	map1[3] = "c";
	map1[2] = "b";
	map1[1] = "a";

	map1 = map_sort(map1);
	cout << "遍历字典" << endl;
	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		cout << iter->first << iter->second << endl;
	}
	
	cout << "*************algorithm算法库中的sort******************" << endl;
	cout << "测试sort函数" << endl;
	test_sort();

	cout << "*************测试常量引用**********************************" << endl;
	int b = 10;
	const int &a = b;
	cout << a << endl;

	cout << "*************************string************************" << endl;
	string s = " abc    ";
	cout << s.substr(1) << endl;

	cout << "********************关联容器、文件流、字符流***************" << endl;
	ifstream input_file("input_file.txt"), map_file("map_file.txt");
	cout << input_file.is_open() << endl;
	words_transform(map_file, input_file);

	cout << "**********************string*************************" << endl;
	test_string();

	cout << "***********************thread 线程类****************" << endl;
	test_thread();

	getchar();
	return 0;
}


