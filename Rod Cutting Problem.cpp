

//Memoization
class Solution {
  public:
    int helper(vector<int> &price, int ind, int len, int n, vector<vector<int>> &dp){
        if(len==0)return 0;
        if(ind==n){
            return -1e9;
        }
        if(dp[ind][len]!=-1){
            return dp[ind][len];
        }
        int notTake = helper(price, ind+1, len ,n, dp);
        int take = INT_MIN;
        if((ind+1)<=len){
            take = price[ind] + helper(price, ind,len-(ind+1),n, dp);
        }
        return dp[ind][len] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n= price.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = helper(price, 0 ,n, n,dp);
        return ans;
    }
};
