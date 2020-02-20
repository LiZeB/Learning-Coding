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
		//long tb = b; // 在后面的代码中不更新b
		//while ((tb + tb) <= a) {
		//	count = count + count; // 最小解翻倍
		//	tb = tb + tb; // 当前测试的值也翻倍
		//}
		//return count + my_divide(a - tb, b);
		/*
		作者：liujin - 4
		链接：https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
		来源：力扣（LeetCode）
		著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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