#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size()<4) {
			return  vector<vector<int>>();
		}
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size() - 3; i++) {
			for (int j = i + 1; j<nums.size() - 2; j++) {
				int L = j + 1;
				int R = nums.size() - 1;
				while (L<R) {
					int sum = nums[i] + nums[j] + nums[L] + nums[R];
					if (sum == target) {
						result.push_back({ nums[i], nums[j], nums[L], nums[R] });
						L++; R--;
					}
					if (sum > target) R--;
					if (sum < target) L++;
				}

			}
		}
		if (result.size() != 0) {
			sort(result.begin(), result.end());
			auto new_end = unique(result.begin(), result.end());
			result.erase(new_end, result.end());
		}
		return result;
	}
};