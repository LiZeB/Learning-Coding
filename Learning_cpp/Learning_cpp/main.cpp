#include<iostream>
#include "characters.h"

int main()
{
    char *input = "Hello World, my name is LiZeBin";     
    vector<string> output;
    output = splict_string(input, ",");
    cout<<"original input:"<<input<<endl;  
	cout << ", as separator:" << endl;
	for (auto iter = output.begin();iter != output.end(); iter++) {
		cout << (*iter) << endl;
	}

	cout << "whitespace as separator:" << endl;
	output = splict_string(input, " ");
	for(decltype(output.size()) i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	cout << "m as separator:" << endl;
	output = splict_string(input, "m");
	for (auto i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	cout << sizeof(int) << endl;
	cout << sizeof(int *) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(double *) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(char *) << endl;
	
	getchar();
	return 0;
}