#include "container.h"

//����vector�ĸ��ֳ�ʼ����ʽ
void test_vector() {
	/****************************************
	v2(v1), v2 = v1 �����ֳ�ʼ����ʽ��һ��
	�ģ�û������
	******************************************/
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2(v1);    
	v2.push_back(6);
	for (auto &iter : v1) {
		cout << iter << " ";
	}
	for (auto &iter : v2) {
		cout << iter << " ";
	}
	cout << endl;

}

template<class T>
void test_queue(queue<T> &q, T val) {
	/*********************************
	�����˶��е�empty������
	**********************************/
	q.push(val);
	cout << "����Ϊ�գ�" << q.empty() << endl;
}

template<class T, class E>
map<T, E>  map_sort(map<T, E> &map1) {
	/******************************
	����map������������
	*******************************/
	struct Point { double x, y; };

	map<T, E> map2(map1.begin(), map1.end());

	return map2;
}

map<string, string> get_map(ifstream &map_file) {
	/********************************************
	�ӵ����û������ļ��л�ȡ�����û�������ֵ�
	*********************************************/
	map<string, string> map_rule;
	string key, mapped_value;
	while (map_file >> key && getline(map_file, mapped_value)) {
		map_rule[key] = mapped_value.substr(1);   //�����substr(1)��ȥ���ո�
	}
	return map_rule;
}

void words_transform(ifstream &map_file, ifstream &input_file) {
	/*********************************************
	��дC++ primer��11.3.6С���г��ֵĵ����û�����
	map_file: �û�������ļ�����
	input_file�������ı����ļ�����
	**********************************************/
	map<string, string> map_rule = get_map(map_file);
	ofstream output_file("result.txt", ofstream::out);

	string index_string;
	while (getline(input_file, index_string)) {
		istringstream s1(index_string);
		string word;
		while (s1 >> word) {
			if (map_rule.find(word) != map_rule.end()) {
				word = map_rule[word];
			}
			output_file << word << " ";
		}
		output_file << endl;
	}
}