#include "recursion.h"

/**
�����ֽ⣺��������һ������д�����������ֽ��ʽ
һ��ʼ�����õݹ鷽����д����������߼��Ƚϼ򵥣����õݹ�Ҳ�ܺܺ�ʵ��
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