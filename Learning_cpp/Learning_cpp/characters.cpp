#include "characters.h"

using namespace std;

vector<string> splict(const char *input, const char *delim){
    /***************************************
     对一个字符串按指定的分割符进行分割，不能修改传递过
     来的要分割的字符串；
     input: 要分割的字符串；
     delim: 指定的分割符
     * *************************************/

	//第一种写法
    /*char *input_ = new char[strlen(input)];
    strcpy(input_, input);
	vector<string> result;
	
    char *token = strtok(input_, delim);
    while(token != NULL){
		result.push_back(token);
		if(input_ != NULL)
			token = strtok(NULL, delim);
    }*/

	//第二种写法
	vector<string> result;
	string s1 = input;
	string::size_type pre_pos=0, cur_pos=0;
	while ((cur_pos = s1.find(delim, pre_pos)) != string::npos) {
		string temp(s1, pre_pos, cur_pos - pre_pos);    //string的构造函数之一
		result.push_back(temp);
		pre_pos = cur_pos + strlen(delim);
	}
	result.push_back(string(s1, pre_pos, s1.length()-pre_pos));
    return result;
}

void test_string1() {
	//构造函数
	string s1 = "";
	s1 += 'a';
	s1 += "abc";       
	//对于string冲在了 += 运算符，注意没有这种 string s = "abc"+"def"，没有对两个常量字符串重载+运算符
	cout << "s1:" << s1 << endl;
	
	//s[i]的元素类型
	cout << s1[0] << endl;
	cout << typeid(s1[0]).name() << endl;
	
	cout << s1.length() << endl;
	string s2 = "abc";   
	cout << s2.length() << endl;
	
	/******************************char *风格的字符串*************************/
	char *s3 = "abc";
	cout << s3 << " " << strlen(s3) << " " << sizeof(s3) << endl;
	cout << s3[3] << endl;     //访问s3[3]没有产生未定义错误，因为char *字符串是以“/0”存储结束
	char s6[] = "abc";
	cout << s6<<" "<<sizeof(s6) << " " << strlen(s6) << endl;  
	//这里sizeof(s6)包含了最后一个字节“\0”，它是4；只是针对数组时是特例
		
	//一定要注意是'\0'，不是'/0'，这一个小错误很难找
	char s7[4];
	s7[0] = 'a', s7[1] = 'b', s7[2] = 'c', s7[3] = '\0';
	cout << " " << strlen(s7) << endl;
	char *s8 = new char[10];
	s8[0] = 'a', s8[1] = 'b', s8[2] = 'c', s8[3] = 'd', s8[4] = '\0';
	cout <<" "<< strlen(s8) << endl;

	//string中的c_str()
	string s4 = "ABC";
	const char *s5 = s4.c_str();
	cout << s5 << endl;

	/***************string中的substr()函数*************/
	std::string a = "0123456789abcdefghij";

	// count 为 npos ，返回 [pos, size())
	std::string sub1 = a.substr(10);
	std::cout << sub1 << '\n';

	// pos 和 pos+count 都在边界内，返回 [pos, pos+count)
	std::string sub2 = a.substr(5, 3);
	std::cout << sub2 << '\n';

	// pos 在边界内， pos+count 不在，返回 [pos, size()) 
	std::string sub4 = a.substr(a.size() - 3, 50);
	std::cout << sub4 << '\n';

	try {
		// pos 在边界外，抛出
		std::string sub5 = a.substr(a.size() + 3, 50);
		std::cout << sub5 << '\n';
	}
	catch (const std::out_of_range& e) {
		std::cout << "pos exceeds string size\n";
	}
}

const string& substrCN(const string &str, int len) {
	/**************************************************************
	一道笔试题：写一个substrCN(str, len)方法，区分单双字节来截取字符；
	英文字符算作1个，汉字算作2个。len表示汉字长度。题目要求以const引
	用作为返回值。
	样例一：
	输入 
	String str a中b国c人d民很行
	int len 2
	输出（String）
	a中b
	样例二：
	输入
	String str a中b国c人d民很行
	int len 3
	输出（string）
	a中b国
	***************************************************************/
	len = 2 * len;
	int count_len = 0;
	vector<char> temp;

	for (int i = 0; i < str.length(); i++) {
		if (count_len >= len) {
			break;
		}
		count_len += 1;
		temp.push_back(str[i]);
	}
	string *result = new string("");
	for (int i = 0; i < temp.size();i++) {
		*result += temp[i];
	}
	return *result;
}

const vector<int>& reverseArray(const vector<int>& array) {
	/***********************************************************
	一道笔试题：将array中的每一个元素逆序输出;题目要求以
	const引用作为返回值
	************************************************************/
	vector<int> result;
	for (int i = array.size() - 1; i >= 0; i--) {
		result.push_back(array[i]);
	}
	vector<int> *v1 = new vector<int>(result);
	return *v1;
}
