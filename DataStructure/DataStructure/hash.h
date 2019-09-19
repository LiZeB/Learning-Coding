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
	哈希表：这里只实现了除留余数法构造哈希函数（只针对整数关键字）、分离链接法解决冲突；
	因为这种组合比较经典；分离链接法解决冲突和探测法解决冲突两种实现难度上差不多。
	在实际中如何构造哈希函数，使元素在整个哈希表种分布均匀是影响哈希表性能的很重要因素。
	另外哈希表的长度最好取为质数。
	哈希表算法的优点是：查找效率高，时间复杂度是O(N),当然前提是在哈希表中分布均匀
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
			advance(iter, 1);    //一定要注意这个advance()函数是迭代器增加指定大小的用法
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
				/*auto iter = table[i].begin();      //这里只是为了测试advance的用法，才写的，但是不能正确运行，原因还不清楚
				for (int i = 0;i < table[i].size()-1;i++) {
					cout << iter->first << " " << iter->second << " ";
					advance(iter, 1);
				}*/
				cout << endl;
			}
	}


protected:
	//定义哈希函数，
	int hash(const K &theKey) const {
		/**********************************
		哈希函数：除留余数法
		***********************************/
		return theKey % divisor;
	}
	list<pair<const K, E>> *table;   //哈希表
	int dSize;    //元素个数             
	int divisor;  //哈希表长度
};

void test_hash() {
	//针对<int, int>类型
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
	cout << "哈希表中元素的个数：" << z1.size() << endl;
	int key = 12;
	p = z1.find(key);
	cout << "关键字:" << key << " ("<<p.first << "," << p.second<<")" << endl;
	z1.erase(1);
	cout << "删除关键字为1的元素：" << endl;
	z1.output(cout);

	//针对<int, string>类型
	hashChains<int, string> x1;
	x1.insert({ 15, "LiZeBin" });
	x1.insert({ 21, "DongZan" });
	x1.insert({ 24, "LiuYuanDu" });
	cout << "删除之前是：" << endl;
	x1.output(cout);
	cout << "删除之后是：" << endl;
	x1.erase(24);
	x1.output(cout);
}
#endif
