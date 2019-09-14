#include "characters.h"
#include "container.cpp"
#include "test_algorithm.cpp"
#include "my_thread.cpp"
#include "oop.cpp"
#include <typeinfo>

int main() {
	cout << "***********һ���Ƚ����ĵı�����********************" << endl;
	int i = 3;
	do {
		if (i++ == 15)       //����д��++i���Ǵ�ӡ�����*���ĳ�i++���Ǵ�ӡ2��
			break;
		if (i++ % 3 == 0)
			printf("*", i);
	} while (1);
	cout << endl;

	cout << "***********splict_string�Ĵ���*********************" << endl;
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

	cout << "***********���������������͵��ֽ���*****************" << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(long):" << sizeof(long) << endl;
	cout << "sizeof(long long):" << sizeof(long long) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char):"<<sizeof(char) << endl;
	cout << "sizeof(char *):"<<sizeof(char *) << endl;
	cout << "sizeof(float):" << sizeof(float) << endl;
	cout << "sizeof(float *):" << sizeof(float *) << endl;


	int a1[] = { 0, 1, 2, 3, 4, 5 };
	char *a2 = "012345";
	cout << "sizeof(a1):" << sizeof(a1) << endl;
	cout << "sizeof(*a1):" << sizeof(*a1) << endl;
	cout << "sizeof(*a2):" << sizeof(*a2) << endl;
	cout << "sizeof(a2):" << sizeof(a2) << endl;

	cout << "********************vector***************************" << endl;
	cout << "����vector" << endl;
	test_vector();

	cout << "*************����************************************" << endl;
	queue<vector<int>> q1;
	test_queue(q1, vector<int>(20));
	
	cout << "*******************map�ֵ�***************************" << endl;
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

	cout << "*************���Գ�������*****************************" << endl;
	int b = 10;
	const int &a = b;
	const int &c = a;
	cout << a <<" "<<c<< endl;

	cout << "*************************string************************" << endl;
	string s = " abc    ";
	cout << s.substr(1) << endl;
	string s1 = "1" + s;
	cout << s1 << endl;

	test_string1();
	vector<int> array{1, 2, 3, 4};
	const vector<int> &result = reverseArray(array);
	for (auto iter : result) {
		cout << iter << endl;
	}
	string src = "a��b��c��d������";
	const string result2 = substrCN(src, 3);
	cout << result2 << endl;

	cout << "********************�����������ļ������ַ���***********" << endl;
	ifstream input_file("input_file.txt"), map_file("map_file.txt");
	cout << input_file.is_open() << endl;
	words_transform(map_file, input_file);

	cout << "***********************thread �߳���*******************" << endl;
	test_thread2();
	cout << endl;

	cout << "***********************�����������********************" << endl;
	test_class_inherited();
	test_class_memory();
	test_class_construction();
	test_class_static();

	cout << "***********************ǿ������ת��********************" << endl;
	int x0 = 65;
	float x1 = static_cast<float>(x0);
	char x2 = static_cast<char>(x0);
	cout << typeid(x1).name()<<" "<<x1<< endl;
	cout << typeid(x2).name()<<" "<<x2<< endl;

	getchar();
	return 0;
}
