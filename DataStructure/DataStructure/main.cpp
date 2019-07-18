#include<iostream>
#include "link_list.cpp"

using namespace std;

int main() {
	chain<int> linkList;

	//��������Ĳ���
	for (int i = 0; i < 10; i++) {
		linkList.insert(i, i);
	}
	linkList.insert(0, 5);
	linkList.insert(1, 2);
	linkList.insert(-1, 3);
	linkList.insert(2, 4);
	linkList.output(cout);

	//��������Ŀ������캯��
	chain<int> linkList2(linkList);
	linkList2.output(cout);

	//��������Ļ�ȡԪ�صĺ���
	int a = 6;
	int temp = linkList2.get(6);
	cout <<"��λ��"<<a<<"��������:"<< temp << endl;

	//���Ը���Ԫ��ֵ����Ԫ��ֵ������
	int temp2 = linkList2.indexOf(1);
	cout <<"ȡĳһ��Ԫ��ֵ"<<temp2<<"��������" <<temp2 << endl;

	//���Ը�������ɾ��ĳһ���
	linkList2.erase(13);
	linkList2.output(cout);
	getchar();
	return 0;
}