class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (auto it : intervals) {
            cout << it[0];
            cout << it[1];
            cout << endl;
        }
        vector<vector<int>> ans = {};
        int i = 0;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && start <= ans.back()[1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(intervals[j][1], end);

                } else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};
