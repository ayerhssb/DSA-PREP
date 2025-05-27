class Solution {
public:
    int helper(int amount, vector<int>& coins, int ind, vector<vector<long long>> &dp){
        if(ind==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }

        long long notTake = 0 + helper(amount, coins, ind-1, dp);
        long long take=0;
        if(coins[ind]<=amount){
            take = helper(amount-coins[ind],coins, ind, dp);
        }

        return dp[ind][amount] = take+notTake;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1,-1));
        int ans=helper(amount, coins, n-1, dp);
        return ans;
    }
};
