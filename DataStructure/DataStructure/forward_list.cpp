#include <sstream>
#include "forward_list.h"
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
	����������ʾ��out�������ļ���Ҳ�����Ǳ�׼���������
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
	/*********************************
	��������theIndex(�±��0��ʼ)��
	ɾ�������е�ĳһ��Ԫ��
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
	ʵ����һ�����������㷨������㷨�Ĺ��������һ��
	������������������һ���Կռ任ʱ���˼�룬����
	������Ԫ��ֵ��[0-(n-1)]��Χ�ڣ�����n������ÿ����
	����ԭ������������ͬԪ�ص�ֵ����n��������[0,(n-1)]
	���±����������������ԭ������ÿһ��Ԫ�ط������Ӻ�
	���ֻ�谴˳���ԭ��������Ԫ�ط����µ����������
	�������һ���ź��������
	��������㷨�����ƣ�����ʹ��ԭ�����е�Ԫ
	��ֵ�����������ֻ�����TΪint���͵����������Ԫ��
	Ҳֻ��Ϊ�Ǹ�����
	range:ԭ���������Ԫ��ֵ+1
	**************************************************/
	chainNode<T> **top, **bottom;
	top = new chainNode<T> *[range];
	bottom = new chainNode<T> *[range];
	for (int i = 0; i < range; i++) {
		top[i] = NULL;
		bottom[i] = NULL;
	}

	//��ԭ�����е�ÿһ��Ԫ����������ӵ���
	while (firstNode != NULL) {
		T tempElement = firstNode->element;    //ģ������Tֻ��Ϊint
		if (bottom[tempElement] == NULL) {
			top[tempElement] = firstNode;
			bottom[tempElement] = firstNode;
		}
		else {
			top[tempElement]->next = firstNode;
			top[tempElement] = firstNode;
		}
		firstNode = firstNode->next;
	}


	/*���Դ��룬���Է��������Ƿ���ȷ*/
	/*cout << "----------------------" << endl;
	for (int j = 0; j < range; j++) {
		if (bottom[j] == NULL) {
			continue;
		}
		chainNode<T> *index = bottom[j];
		while (index != top[j]) {
			cout << index->element;
			index = index->next;
		}
		cout<<index->element<< endl;
	}
	cout << "----------------------" << endl;
	************************************/

	//�����ӵ���ȡԪ�ط���һ������ʹ֮��Ϊһ���µ���������
	int start = 0;
	for (int bin = 0; bin < range; bin++) {
		if (bottom[bin] != NULL)
			break;
		start++;
	}
	cout << start << endl;
	int skip_flag = 0;
	for (int bin = start; bin < range; bin++) {
		if (bottom[bin] == NULL) {
			skip_flag++;
			continue;
		}
		if (bin == start) {
			firstNode = bottom[bin];
		}
		else {
			top[bin-1-skip_flag]->next = bottom[bin];
			skip_flag = 0;
		}
	}
	top[range - 1]->next = NULL;    
}

template<class T>
T chain<T>::getMax() const {       
	/************************************
	ʵ����һ�����������ȡ��ǰ�������ֵ�ĺ���
	ע�����ﷵ��ֵ����Ϊ����
	*************************************/
	if (listSize == 0) {
		cout << "����Ϊ��" << endl;
		exit(0);
	}
	chainNode<T> *indexNode = firstNode;
	T maxValue = firstNode->element;
	while (indexNode != NULL) {
		if (maxValue < indexNode->element)
			maxValue = indexNode->element;
		indexNode = indexNode->next;
	}
	return maxValue;
}

void test_forward_list() {
	chain<int> linkList;

	//��������Ĳ���
	for (int i = 0; i < 14; i++) {
		linkList.insert(i, 17 - i);
	}
	linkList.output(cout);

	//��������Ŀ������캯��
	chain<int> linkList2(linkList);
	linkList2.output(cout);

	//��������Ļ�ȡԪ�صĺ���
	int a1 = 6;
	int temp = linkList2.get(a1);
	cout << "��λ��" << a1 << "��������:" << temp << endl;

	//���Ը���Ԫ��ֵ����Ԫ��ֵ������
	int temp2 = linkList2.indexOf(13);
	cout << "ȡĳһ��Ԫ��ֵ" << 13 << "��������" << temp2 << endl;

	//���Ը�������ɾ��ĳһ���
	linkList2.erase(13);
	cout << "ɾ������λ��" << 13 << "��Ԫ�أ�" << endl;
	linkList2.output(cout);

	//���������������㷨�������������
	linkList2.insert(5, 118);
	linkList2.output(cout);
	linkList2.insert(2, 18);
	linkList2.output(cout);
	linkList2.binSort(linkList2.getMax() + 1);
	linkList2.output(cout);
}