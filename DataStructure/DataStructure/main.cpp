#include<iostream>
#include "link_list.cpp"

using namespace std;

int main() {
	chain<int> linkList;
	for (int i = 0; i < 10; i++) {
		linkList.insert(i, i);
	}
	linkList.insert(0, 5);
	linkList.insert(1, 2);
	linkList.insert(-1, 3);
	linkList.insert(2, 4);
	linkList.output(cout);

	chain<int> linkList2(linkList);
	linkList2.output(cout);
	getchar();
	return 0;
}