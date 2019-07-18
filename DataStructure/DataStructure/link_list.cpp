#include <sstream>
#include "data_structure.h"
using namespace std;


template<class T>
chain<T>::chain(int initialCapacity) {
	/************************************
	构造函数，这里的initialCapacity暂时还没发挥作用；
	它是一个默认参数，默认值为100
	*************************************/
	if(initialCapacity < 1) {
		ostringstream s;
		s << "initialCapacity = " << initialCapacity << "Must be > 0";
	}
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T> &theList) {
	/*************************************
	拷贝对象构造函数
	**************************************/
	listSize = theList.listSize;
	if (listSize == 0) {
		firstNode = NULL;
		return;
	}
	chainNode<T> *sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T> *targetNode = firstNode;
	while(sourceNode != NULL) {
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

template<class T>
void chain<T>::insert(int theIndex, const T &theElement) {
	/***************************************
	链表的插入函数：
	1.theIndex <=0:在首位置插入；
	2.theIndex >= listSize:在尾部插入；
	3.listSize ==0:插入第一个元素
	4.其它：在中间位置插入
	***************************************/
	if (listSize == 0) {
		chainNode<T> *tempNode = new chainNode<T>(theElement);
		firstNode = tempNode;
	}
	else if (theIndex >= listSize) {
		chainNode<T> *tempNode = firstNode;
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
		}
		tempNode->next = new chainNode<T>(theElement);
	}
	else if (theIndex <= 0) {
		chainNode<T> *tempNode = new chainNode<T>(theElement, firstNode);
		firstNode = tempNode;
	}
	else {
		int i = 0;
		chainNode<T> *tempNode = firstNode;
		while ((i < theIndex-1) && (tempNode !=NULL)) {
			tempNode = tempNode->next;
			i++;
		}
		chainNode<T> *tempNode2 = new chainNode<T>(theElement, tempNode->next);
		tempNode->next = tempNode2;
	}
	listSize += 1;
}

template<class T>
void chain<T>::output(ostream &out) const {
	/*****************************
	链表的输出
	******************************/
	cout << "The length of the chain is "<<listSize<< " " << endl;
	if (listSize == 0) {
		out << "The chain is NULL" << endl;
	}
	chainNode<T> *indexNode = firstNode;
	while (indexNode != NULL) {
		out << indexNode->element << " ";
		indexNode = indexNode->next;
	}
	out << endl;
}

template<class T>
chain<T>::~chain() {
	/************************************
	chain这个链表类的析构函数
	*************************************/
	while (firstNode != NULL) {
		chainNode<T> *indexNode = firstNode->next;
		delete firstNode;
		firstNode = indexNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const {
	/*************************************
	根据某一个索引获取当前链表中的元素；
	theIndex是从0开始
	**************************************/
	if (theIndex < 0 || theIndex > listSize) {
		cout << "theIndex" <<theIndex  <<"must be >0" << endl;
		exit(0);
	}
	chainNode<T> *indexNode = firstNode;
	int i = 0;
	while (i < theIndex) {
		indexNode = indexNode->next;
		i++;
	}
	return indexNode->element;
}

template<class T>
int chain<T>::indexOf(const T &theElement) const {
	/****************************************
	返回链表中与theElement有相同元素值得第一个索引；
	索引从0开始
	*****************************************/
	chainNode<T> *indexNode = firstNode;
	int i = 0;
	while ((indexNode != NULL) && (indexNode->element != theElement)) {
		indexNode = indexNode->next;
		i++;
	}
	if (indexNode == NULL) {
		return -1;
	}
	else
		return i;
}

template<class T>
void chain<T>::erase(int theIndex) {
	if (theIndex < 0 || theIndex >= listSize) {
		cout << "theIndex is not correct!" << endl;
		exit(0);
	}
	chainNode<T> *tempNode=firstNode;
	if (theIndex == 0) {
		delete firstNode;
		firstNode = tempNode;
	}
	else if (theIndex == (listSize - 1)) {
		chainNode<T> *preNode=tempNode;
		while (tempNode->next != NULL) {
			preNode = tempNode;
			tempNode = tempNode->next;
		}
		preNode->next = NULL;
		delete tempNode;
	}
	else {
		chainNode<T> *preNode=tempNode;
		int i = 0;
		while (i<theIndex) {
			preNode = tempNode;
			tempNode = tempNode->next;
			i++;
		}
		preNode->next = tempNode->next;
		delete tempNode;
	}
	listSize--;
}