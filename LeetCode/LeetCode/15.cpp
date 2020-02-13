#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ------------暴力解法---------------   
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		if (nums[0]>0 || nums[nums.size() - 1]<0)
			return  vector<vector<int>>();
		int mid = nums.size();

		for (int i = mid; i>0; i--) {
			for (int j = 0; j<i; j++) {
				for (int k = i + 1; k<nums.size(); k++) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						result.push_back(tmp);
					}
				}
			}
		}
		sort(result.begin(), result.end());
		auto new_end = unique(result.begin(), result.end());
		result.erase(new_end, result.end());

		return result;
	}
};

// ---------------------双指针解法-----------------------------
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		if (nums.size()<3 || nums[0]>0 || nums[nums.size() - 1]<0) {
			return vector<vector<int>>();
		}
		if (nums.size() == 3) {
			if (nums[0] + nums[1] + nums[2] == 0) {
				vector<int> tmp;
				tmp.push_back(nums[0]);
				tmp.push_back(nums[1]);
				tmp.push_back(nums[2]);
				result.push_back(tmp);
			}
			else {
				return vector<vector<int>>();
			}

		}
		for (int i = 0; i<nums.size() - 2; i++) {
			if (nums[i]>0) break;
			int L = i + 1;
			int R = nums.size() - 1;
			while (L<R) {
				int sum = nums[i] + nums[L] + nums[R];
				if (sum == 0) {
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[L]);
					tmp.push_back(nums[R]);
					result.push_back(tmp);
					R--;
					while ((nums[R] == nums[R + 1]) && (R>L)) R--;
					L++;
					while ((nums[L] == nums[L - 1]) && (L<R)) L++;
				}
				if (sum>0) {
					R--;
					while ((nums[R] == nums[R + 1]) && (R>L)) R--;
				}
				if (sum<0) {
					L++;
					while ((nums[L] == nums[L - 1]) && (L<R)) L++;
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