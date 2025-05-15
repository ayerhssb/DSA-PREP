//memoization
class Solution {
public:
    int helper(int i, vector<int>& dp){
        if(dp[i]!=-1){return dp[i];}
        if(i==2|| i==1){return i;}
        return dp[i] = helper(i-1, dp)+helper(i-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = helper(n,dp);
        return ans;
    }
};
