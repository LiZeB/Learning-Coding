#ifndef CHARACTERS_H
#define CHARACTERS_H
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include <typeinfo>


using namespace std;

vector<string> my_splict(const char *input, const char* delim);

char* my_strcpy(char *dst, const char *src);

int my_strcmp(const char *dst, const char *src);

void test_string1();

void test_str_functions();

void test_exam_functions();


const string& substrCN(const string &str, int len);

const vector<int>& reverseArray(const vector<int>& array);
#endif // CHARACTERS_H