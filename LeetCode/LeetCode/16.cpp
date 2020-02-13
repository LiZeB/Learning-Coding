#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result, subtraction = INT_MAX;
		sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size() - 2; i++) {
			int R = nums.size() - 1;
			int L = i + 1;
			while (L<R) {
				int sum = nums[L] + nums[R] + nums[i];
				if (abs(sum - target)<subtraction) {
					result = sum;
					subtraction = abs(sum - target);
				}
				if (sum == target) return target;
				if (sum > target) {
					if (R > L) R--;
				}
				if (sum < target) {
					if (L < R) L++;
				}
			}
		}
		return result;
	}

};