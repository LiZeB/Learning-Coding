#include "recursion.h"

/**
质数分解：给定任意一个数，写出它的质数分解等式
一开始打算用递归方法来写，结果发现逻辑比较简单，不用递归也能很好实现
**/
void prime_number_deComponent(int number) {
	static int k = 2;
	cout << number << "=";
	while (true) {
		if ((number%k == 0) && (number!=k)) {
			cout << k << "*";
			number = number / k;
		}
		else if((number%k!=0)&&(number!=k)){
			k++;
		}
		else {
			cout << k;
			break;
		}
	}
	cout << endl;
}

void test_recursion() {
	int n = 2224;
	prime_number_deComponent(n);
}