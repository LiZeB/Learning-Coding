#include "characters.h"

using namespace std;

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
	cout << s3 << " strlen(s3)=" << strlen(s3) << " sizeof(s3)=" << sizeof(s3) << endl;
	cout << "sizeof(\"abcde\") " << sizeof("abcde") << endl;
	cout << s3[3] << endl;    
	char s6[] = "abc";
	cout << s6<<" sizeof(s6)="<<sizeof(s6) << " strlen(s6)=" << strlen(s6) << endl;  
	//s3[1] = 'e';   //写只读内存，运行时报错
	s6[1] = 'e';
	cout << "s3=" << s3 << " s6=" << s6 << endl;
	char s9[2][5] = {};
	cout << "s9  " << sizeof(s9) << endl;
	cout << "*s9+1 " << sizeof(*(s9 + 1)) << endl;
		
	char s7[5] = {'a', 'b', 'c', 'd', '\0'};   //一定要注意是'\0'，不是'/0'，这一个小错误很难找
	//s7[0] = 'a', s7[1] = 'b', s7[2] = '\0', s7[3] = 8, s7[4]='\0';
	cout << "s7: " << strlen(s7) <<" "<< sizeof(s7) << endl;
	char *s8 = new char[10];
	s8[0] = 'a', s8[1] = 'b', s8[2] = 'c', s8[3] = 'd', s8[4] = '\0';
	cout <<" "<< strlen(s8) << endl;

	string s4 = "ABC";    //string中的c_str()
	const char *s5 = s4.c_str();
	cout << s5 << endl;

	/***************string中的substr()函数*************/
	std::string a = "0123456789abcdefghij";

	std::string sub1 = a.substr(10);   // count 为 npos ，返回 [pos, size())
	std::cout << sub1 << '\n';

	std::string sub2 = a.substr(5, 3);   // pos 和 pos+count 都在边界内，返回 [pos, pos+count)
	std::cout << sub2 << '\n';

	std::string sub4 = a.substr(a.size() - 3, 50);  // pos 在边界内， pos+count 不在，返回 [pos, size()) 
	std::cout << sub4 << '\n';

	try {
		std::string sub5 = a.substr(a.size() + 3, 50);  // pos 在边界外，抛出
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
	cout << str.length() << endl;
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

void test_exam_functions() {
	string s = " abc    ";
	cout << s.substr(1) << endl;
	string s1 = "1" + s;
	cout << s1 << endl;

	vector<int> array{1, 2, 3, 4};
	const vector<int> &result = reverseArray(array);
	for (auto iter : result) {
		cout << iter << endl;
	}
	string src = "a中b国c人d民银行.";   //控制台string中带中文会显示乱码
	string result2 = substrCN(src, 3);
	cout << result2 << endl;
}

vector<string> my_splict(const char *input, const char *delim) {
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
	string::size_type pre_pos = 0, cur_pos = 0;
	while ((cur_pos = s1.find(delim, pre_pos)) != string::npos) {
		string temp(s1, pre_pos, cur_pos - pre_pos);    //string的构造函数之一
		result.push_back(temp);
		pre_pos = cur_pos + strlen(delim);
	}
	result.push_back(string(s1, pre_pos, s1.length() - pre_pos));
	return result;
}

char* my_strcpy(char *dst, const char *src) {
	const char *index1 = src;
	char *index2 = dst;
	while ((*index2++ = *index1++) != '\0');
	return dst;
}

int my_strcmp(const char *dst, const char *src) {
	const char *index1 = dst, *index2 = src;
	//char *index1 = const_cast<char *>(dst), *index2 = const_cast<char *>(src);
	int flag = 0;
	while ((*index1 != '\0') && (*index2 != '\0')) {
		if (*index1 > *index2) {
			flag = 1;
			break;
		}
		else if (*index1 < *index2) {
			flag = -1;
			break;
		}
		else {
			index1++;
			index2++;
		}
	}

	if (flag == 0) {
		if (*index1 == '\0' && *index2 != '\0') return -1;
		if (*index1 != '\0' && *index2 == '\0') return 1;
		return 0;
	}

	return flag;
}

void* my_memcpy(void *dest, const void *src, size_t count) {
	char *dest_ = (char *)dest;
	const char *src_ = (char*)src;
	while (count--) {
		*dest_++ = *src_++;
	}

	return dest;
}

void test_str_functions() {
	cout << "test splict function:" << endl;
	{
		const char *input = "Hello World, my name is LiZeBin";
		vector<string> output;
		output = my_splict(input, ",");
		cout << "original input:" << input << endl;
		cout << ", as separator:" << endl;
		for (auto iter = output.begin();iter != output.end(); iter++) {
			cout << (*iter) << endl;
		}

		cout << "whitespace as separator:" << endl;
		output = my_splict(input, " ");
		for (decltype(output.size()) i = 0; i < output.size(); i++) {
			cout << output[i] << endl;
		}

		cout << "my as separator:" << endl;
		output = my_splict(input, "my");
		for (auto i = 0; i < output.size(); i++) {
			cout << output[i] << endl;
		}
	}

	cout << "test strcpy function:" << endl;
	{
		char *temp = "abc";
		const char *src = "abcde";
		char *dst = new char[strlen(src) + 1];
		my_strcpy(dst, src);
		cout << dst << endl;
	}

	cout << "test strcmp function:" << endl;
	{
		char *dst = "abcde", *temp = "abc";
		cout << my_strcmp(dst, temp) << endl;
	}

	cout << "test memcpy function:" << endl;
	{
		char *dst = new char[10], *src = "abcde";
		my_memcpy(dst, src, strlen(src)+1);
		cout << dst << endl;
	}
}