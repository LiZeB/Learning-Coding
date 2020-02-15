class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()<2) {
			return nums.size();
		}

		int result = nums.size();
		int count = 0, i = 1;
		while (i< nums.size() - count) {
			if (nums[i - 1] == nums[i]) {
				for (int j = i + 1; j<nums.size() - count; j++) {
					nums[j - 1] = nums[j];
				}
				count++;
			}
			else {
				i++;
			}
		}

		return result - count;
	}
};