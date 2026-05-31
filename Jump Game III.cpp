class Solution {
public:
    bool helper(vector<int>& arr, int idx, vector<int>& dp, vector<int>& vis) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        if (arr[idx] == 0) {
            return true;
        }
        bool right = false, left = false;
        int leftidx = idx- arr[idx], rightidx = idx+arr[idx];
        if (leftidx >= 0) {
            if (!vis[leftidx]) {
                vis[leftidx] = 1;
                left = helper(arr, leftidx, dp, vis);
            }
        }
        if (rightidx < arr.size()) {
            if (!vis[rightidx]) {
                vis[rightidx] = 1;
                right = helper(arr, rightidx, dp, vis);
            }
        }
        return dp[idx] = left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        vector<int> vis(n, 0);
        return helper(arr, start, dp, vis);
    }
};
