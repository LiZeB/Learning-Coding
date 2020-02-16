class Solution {
public:
	bool isValid(string s) {
		bool result;
		vector<char> s1;
		for (int i = 0; i<s.length(); i++) {
			if (s1.size() == 0) {
				s1.push_back(s[i]);
			}
			else {
				auto it = s1.end();
				it--;
				if ((*it == '[' && s[i] == ']') || (*it == '{' && s[i] == '}') || (*it == '(' && s[i] == ')')) {
					s1.erase(it);
				}
				else {
					s1.push_back(s[i]);
				}
			}
		}
		if (s1.size() != 0) {
			return false;
		}
		else {
			return true;
		}
	}
};