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


//tabulization
int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[1]=2;
        dp[0]=1;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
}


//space optimization

int climbStairs(int n) {
        if(n==1) return 1;
        int prev1=2;
        int prev2=1;
        int cur;
        for(int i=2;i<n;i++){
            cur=prev1+prev2;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
}
