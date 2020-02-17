class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n <= 0) {
			return;
		}
		if (m <= 0) {
			nums1 = nums2;
			return;
		}
		vector<int> result;
		int i = 0, j = 0;
		while ((i<m) && (j<n)) {
			if (nums1[i] > nums2[j]) {
				result.push_back(nums2[j]);
				j++;
			}
			else {
				result.push_back(nums1[i]);
				i++;
			}
		}

		if (m>i) {
			for (int k = i; k<m; k++) {
				result.push_back(nums1[k]);
			}
		}
		if (n>j) {
			for (int k = j; k<n; k++) {
				result.push_back(nums2[k]);
			}
		}

		nums1 = result;
	}
};