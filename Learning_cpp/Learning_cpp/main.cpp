#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"
#include "my_thread.cpp"

int main() {
	cout << "***********splict_string�Ĵ���************" << endl;
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

	cout << "***********���������������͵��ֽ���*********" << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;

	cout << "********************vector*********************" << endl;
	cout << "����vector" << endl;
	test_vector();

	cout << "*************����*****************************" << endl;
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	cout << "*******************map�ֵ�********************" << endl;
	map<int, char*> map1;
	map1[3] = "c";
	map1[2] = "b";
	map1[1] = "a";

	map1 = map_sort(map1);
	cout << "�����ֵ�" << endl;
	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		cout << iter->first << iter->second << endl;
	}
	
	cout << "*************algorithm�㷨���е�sort******************" << endl;
	cout << "����sort����" << endl;
	test_sort();

	cout << "*************���Գ�������**********************************" << endl;
	int b = 10;
	const int &a = b;
	cout << a << endl;

	cout << "*************************string************************" << endl;
	string s = " abc    ";
	cout << s.substr(1) << endl;

	cout << "********************�����������ļ������ַ���***************" << endl;
	ifstream input_file("input_file.txt"), map_file("map_file.txt");
	cout << input_file.is_open() << endl;
	words_transform(map_file, input_file);

	cout << "**********************string*************************" << endl;
	test_string();

	cout << "***********************thread �߳���****************" << endl;
	test_thread();

	getchar();
	return 0;
}


