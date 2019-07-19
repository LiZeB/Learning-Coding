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
	链表的输出显示，out可以是文件流也可以是标准输入输出流
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
	/*********************************
	按照索引theIndex(下标从0开始)，
	删除链表中的某一个元素
	**********************************/
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

template<class T>
void chain<T>::binSort(int range) {
	/************************************************
	实现了一个箱子排序算法，这个算法的功能是针对一个
	链表进行排序。排序采用一种以空间换时间的思想，假设
	链表中元素值在[0-(n-1)]范围内，生成n个链表。每个链
	表保存原链表中所有相同元素的值。这n个链表以[0,(n-1)]
	的下标进行索引。这样把原链表中每一个元素放入箱子后，
	最后只需按顺序把原箱子所有元素放入新的链表，这个新
	链表就是一个排好序的链表。
	这个排序算法有限制，条件很强：由于使用原链表中的元
	素值做索引，因此只能针对T为int类型的情况，排序元素
	也只能为非负整数
	range:原链表中最大元素值+1
	**************************************************/
	chainNode<T> **top, **bottom;
	top = new chainNode<T> *[range];
	bottom = new chainNode<T> *[range];
	for (int i = 0; i < range; i++) {
		top[i] = NULL;
		bottom[i] = NULL;
	}

	//把原链表中的每一个元素添加入箱子当中
	while (firstNode != NULL) {
		int tempElement = firstNode->element;    //模板类型T只能为int
		if (top[tempElement] == NULL) {
			top[tempElement] = firstNode;
			bottom[tempElement] = firstNode;
		}
		else {
			top[tempElement]->next = firstNode;
			top[tempElement] = firstNode;
		}
		firstNode = firstNode->next;
	}

	//从箱子当中取元素放入一个链表，使之成为一个新的排序链表
	int start = 0;
	for (int bin = 0; bin < range; bin++) {
		if (top[bin] != NULL)
			break;
		start++;
	}
	int skip_flag = 0;
	for (int bin = start; bin < range; bin++) {
		if (top[bin] == NULL) {
			skip_flag++;
			continue;
		}
		if ((bin == start) && (top[bin] != NULL)) {
			firstNode = bottom[bin];
		}
		else {
			top[bin-1-skip_flag]->next = bottom[bin];
			skip_flag = 0;
		}

	}
	top[range - 1]->next = NULL;    
}