#include "characters.h"

vector<string> splict_string(const char *input, const char *delim){
    /***************************************
     对一个字符串按指定的分割符进行分割，不能修改传递过
     来的要分割的字符串；
     input: 要分割的字符串；
     delim: 指定的分割符
     * *************************************/
    char *input_ = new char[strlen(input)];
    strcpy(input_, input);
	vector<string> result;
	/******使用strtok库函数完成这个功能时不断地出现各种错误*******/
    char *token = std::strtok(input_, delim);
    while(token != NULL){
		result.push_back(token);
		if(input_ != NULL)
			token = strtok(NULL, delim);
    }
    return result;
}