class Solution {
public:
	void sortColors(vector<int>& nums) {
		int count[3] = { 0, 0, 0 };
		for (auto it = nums.begin(); it != nums.end(); it++) {
			count[*it]++;
		}

		int i = 0;
		auto it = nums.begin();
		for (int i = 0; i<3; i++) {
			for (int j = 0; j<count[i]; j++) {
				*it++ = i;
			}
		}
	}
};