#ifndef hashChains_
#define hashChains_

#include<iostream>
#include<utility> 
#include<vector>
#include<list>
#include<string>
#include<iterator>

using namespace std;

template<class K, class E>
class hashChains
{
	/**************************************************************
	��ϣ������ֻʵ���˳��������������ϣ������ֻ��������ؼ��֣����������ӷ������ͻ��
	��Ϊ������ϱȽϾ��䣻�������ӷ������ͻ��̽�ⷨ�����ͻ����ʵ���Ѷ��ϲ�ࡣ
	��ʵ������ι����ϣ������ʹԪ����������ϣ���ֲַ�������һ��Ӱ���ϣ�����ܵĺ���Ҫ�����ء�
	�����ϣ��ĳ������ȡΪ������
	��ϣ���㷨���ŵ��ǣ�����Ч�ʸߣ�ʱ�临�Ӷ���O(N),��Ȼǰ�����ڹ�ϣ���зֲ�����
	****************************************************************/
public:
	hashChains(int theDivisor = 11){
		divisor = theDivisor;
		dSize = 0;

		table = new list<pair<const K, E>>[divisor];
	}

	~hashChains() { delete[] table; }

	bool empty() const { return dSize == 0; }
	int size() const { return dSize; }

	pair<const K, E>&  find(const K& theKey) const{
		int index = (int)hash(theKey) % divisor;
		for (auto element : table[index]) {
			if (element.first == theKey) {
				return element;
			}
		}
		return pair<const K, E>();
	}

	void insert(const pair<const K, E>& thePair){
		int homeBucket = hash(thePair.first) % divisor;
		table[homeBucket].insert(table[homeBucket].begin(), thePair);
		dSize++;	
	}

	void erase(const K& theKey){
		int index = hash(theKey) % divisor;
		auto iter = table[index].begin();
		for (int i = 0; i < table[index].size();i++) {
			if (theKey == iter ->first) {
				table[index].erase(iter);
				break;
			}
			advance(iter, 1);    //һ��Ҫע�����advance()�����ǵ���������ָ����С���÷�
		}
	}

	void output(ostream& out) const{
		for (int i = 0; i < divisor; i++)
			if (table[i].size() == 0)
				cout << "NULL" << endl;
			else {
				for (auto element : table[i]) {
					cout << element.first << " " << element.second << " ";
				}
				/*auto iter = table[i].begin();      //����ֻ��Ϊ�˲���advance���÷�����д�ģ����ǲ�����ȷ���У�ԭ�򻹲����
				for (int i = 0;i < table[i].size()-1;i++) {
					cout << iter->first << " " << iter->second << " ";
					advance(iter, 1);
				}*/
				cout << endl;
			}
	}


protected:
	//�����ϣ������
	int hash(const K &theKey) const {
		/**********************************
		��ϣ����������������
		***********************************/
		return theKey % divisor;
	}
	list<pair<const K, E>> *table;   //��ϣ��
	int dSize;    //Ԫ�ظ���             
	int divisor;  //��ϣ����
};
#endif
