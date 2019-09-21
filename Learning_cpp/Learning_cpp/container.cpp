#include "container.h"
template<class T>
struct map_sort{
	bool  operator ()(T p1, T p2) {
		/******************************
		����ıȽϺ���
		*******************************/
		return p1 >= p2;

	}
};

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

template<class T, class E>
void map_erase(map<T, E> & m1) {
	auto iter = m1.begin();
	while (iter != m1.end()) {
		if (iter->second == "invalid") {
			iter = m1.erase(iter);    //ɾ���ֵ��е�һ��Ԫ�أ������ظ�Ԫ�غ����Ԫ�ص�����
		}
		else {
			iter++;
		}
	}
}

void test_map() {
	cout << "map erase:" << endl;
	{
		map<string, string> m1 = {
			{ "123", "invalid" },
			{ "456", "invalid_12" },
			{ "789", "invalid_123" },
			{ "910", "invalid_12456" }
		};
		map_erase(m1);
		for (auto &element : m1) {
			cout << element.first << " " << element.second << endl;
		}
	}

	cout << "map sort:" << endl;
	{
		map<int, char*, map_sort<int>> map1;   
		map1[3] = "c";
		map1[2] = "b";
		map1[1] = "a";
		for (auto &element : map1) {
			cout << element.first << " " << element.second << endl;
		}
	}
}

void test_vector() {
	/****************************************
	����vector�ĸ��ֳ�ʼ����ʽ
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