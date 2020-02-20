class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0 || intervals.size() == 1) {
			return intervals;
		}

		vector<vector<int>> result = merge1(intervals);
		return result;
	}

	void display(vector<vector<int>>&nums) {
		for (int i = 0; i<nums.size(); i++) {
			for (int j = 0; j<nums[i].size(); j++) {
				cout << nums[i][j] << " ";
			}
			cout << endl;
		}
	}

	vector<vector<int>> merge1(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		sort(intervals.begin(), intervals.end());

		result.push_back(intervals[0]);
		for (int i = 1; i<intervals.size(); i++) {
			auto it = result.end();
			--it;
			if (intervals[i][0] <= (*it)[1]) {
				if (intervals[i][1] >= (*it)[1]) {
					*it = vector<int>({ (*it)[0], intervals[i][1] });
				}
			}
			else {
				result.push_back(intervals[i]);
			}
		}
		return result;
	}
};