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
	��ʵ������ι����ϣ������ʹԪ����������ϣ���ֲַ�������Ӱ���ϣ�����ܵĺ���Ҫ���ء�
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
				cout << endl;
			else {
				for (auto element : table[i]) {
					cout << "("<<element.first << "," << element.second << ") ";
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

void test_hash() {
	//���<int, int>����
	hashChains<int, int> z1;
	z1.insert({ 1,1 });

	pair<int, int> p;
	p.first = 2; p.second = 10;
	z1.insert(p);
	p.first = 10; p.second = 50;
	z1.insert(p);
	p.first = 24; p.second = 120;
	z1.insert(p);
	p.first = 32; p.second = 160;
	z1.insert(p);
	p.first = 3; p.second = 15;
	z1.insert(p);
	p.first = 12; p.second = 60;
	z1.insert(p);
	p.first = 23; p.second = 90;
	z1.insert(p);
	p.first = 34; p.second = 120;
	z1.insert(p);
	z1.output(cout);
	cout << "��ϣ����Ԫ�صĸ�����" << z1.size() << endl;
	int key = 12;
	p = z1.find(key);
	cout << "�ؼ���:" << key << " ("<<p.first << "," << p.second<<")" << endl;
	z1.erase(1);
	cout << "ɾ���ؼ���Ϊ1��Ԫ�أ�" << endl;
	z1.output(cout);

	//���<int, string>����
	hashChains<int, string> x1;
	x1.insert({ 15, "LiZeBin" });
	x1.insert({ 21, "DongZan" });
	x1.insert({ 24, "LiuYuanDu" });
	cout << "ɾ��֮ǰ�ǣ�" << endl;
	x1.output(cout);
	cout << "ɾ��֮���ǣ�" << endl;
	x1.erase(24);
	x1.output(cout);
}
#endif
