class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n == 0)
			return res;
		if (n == 1)
		{
			res.push_back("()");
			return res;
		}
		string s = "";
		for (int i = 0;i < n;++i)
			s += "()";
		sort(s.begin(), s.end());
		cout << s << endl;
		do {
			if (IsLegal(s))
				res.push_back(s);
		} while (next_permutation(s.begin() + 1, s.end()));
		return res;
	}
	bool IsLegal(string& s)
	{
		int count = 0;
		for (int i = 0;i < s.size();++i)
		{
			if (s[i] == '(')
				count++;
			else
				count--;
			if (count<0)
				return false;
		}
		return true;

	}
};
/*
���ߣ�he-fei-si-tuo-si-r
���ӣ�https://leetcode-cn.com/problems/generate-parentheses/solution/c-jian-dan-de-bao-li-qiu-jie-fa-by-he-fei-si-tuo-s/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/