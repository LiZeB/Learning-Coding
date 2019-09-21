#include "container.h"
template<class T>
struct map_sort{
	bool  operator ()(T p1, T p2) {
		/******************************
		排序的比较函数
		*******************************/
		return p1 >= p2;

	}
};

map<string, string> get_map(ifstream &map_file) {
	/********************************************
	从单词置换规则文件中获取单词置换规则的字典
	*********************************************/
	map<string, string> map_rule;
	string key, mapped_value;
	while (map_file >> key && getline(map_file, mapped_value)) {
		map_rule[key] = mapped_value.substr(1);   //这里的substr(1)是去掉空格
	}
	return map_rule;
}

void words_transform(ifstream &map_file, ifstream &input_file) {
	/*********************************************
	重写C++ primer第11.3.6小节中出现的单词置换程序
	map_file: 置换规则的文件流；
	input_file：输入文本的文件流；
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
			iter = m1.erase(iter);    //删除字典中的一个元素，并返回该元素后面的元素迭代器
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
	测试vector的各种初始化方式
	v2(v1), v2 = v1 这两种初始化方式是一样
	的，没有区别；
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
	测试了队列的empty操作；
	**********************************/
	q.push(val);
	cout << "队列为空：" << q.empty() << endl;
}