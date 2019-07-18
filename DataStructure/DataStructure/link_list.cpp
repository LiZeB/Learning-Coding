#include <sstream>
#include "data_structure.h"
using namespace std;


template<class T>
chain<T>::chain(int initialCapacity) {
	/************************************
	���캯���������initialCapacity��ʱ��û�������ã�
	����һ��Ĭ�ϲ�����Ĭ��ֵΪ100
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
	���������캯��
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
	����Ĳ��뺯����
	1.theIndex <=0:����λ�ò��룻
	2.theIndex >= listSize:��β�����룻
	3.listSize ==0:�����һ��Ԫ��
	4.���������м�λ�ò���
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
	��������
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
	chain������������������
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
	����ĳһ��������ȡ��ǰ�����е�Ԫ�أ�
	theIndex�Ǵ�0��ʼ
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
	������������theElement����ͬԪ��ֵ�õ�һ��������
	������0��ʼ
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