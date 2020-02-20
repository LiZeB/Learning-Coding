#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		/*
		if(dividend==INT_MIN && divisor == -1){
		return INT_MAX;
		}
		return dividend/divisor;
		*/
		if (dividend == INT_MIN) {
			if (divisor == 1)
				return INT_MIN;
			if (divisor == -1)
				return INT_MAX;
		}
		if (dividend == INT_MAX && divisor == 1) {
			return INT_MAX;
		}

		int flag = 1;
		if (dividend<0 && divisor>0) {
			flag = -1;
		}
		if (dividend>0 && divisor<0) {
			flag = -1;
		}
		long dividend_ = dividend;
		long divisor_ = divisor;
		dividend_ = dividend_>0 ? dividend_ : -dividend_;
		divisor_ = divisor_>0 ? divisor_ : -divisor_;
		int result = my_divide(dividend_, divisor_);
		return flag*result;
	}
	int my_divide(long a, long b) {
		if (a < b) {
			return 0;
		}
		long count = 0;
		long  db = b;
		while(db<=a) {
			count+=1;
			db = db + b;
		}
		return count + my_divide(a-db, b);

		//if (a<b) return 0;
		//long count = 1;
		//long tb = b; // �ں���Ĵ����в�����b
		//while ((tb + tb) <= a) {
		//	count = count + count; // ��С�ⷭ��
		//	tb = tb + tb; // ��ǰ���Ե�ֵҲ����
		//}
		//return count + my_divide(a - tb, b);
		/*
		���ߣ�liujin - 4
		���ӣ�https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
		��Դ�����ۣ�LeetCode��
		����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
		*/
	}
};


int main() {
	Solution s;
	int result = s.divide(25000, 5);
	cout << result << endl;
	
	getchar();
	return 0;
}