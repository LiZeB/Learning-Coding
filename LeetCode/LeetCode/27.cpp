class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) {
			return 0;
		}

		int result;
		int pre = 0, cur = 0;
		while (cur<nums.size()) {
			if (val == nums[cur]) {
				cur++;
			}
			else {
				nums[pre] = nums[cur];
				pre++;
				cur++;
			}
		}

		return pre;

	}
};