class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind, vector<vector<int>> &dp){

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        if(ind==0){
            if(amount%coins[0]==0){return amount/coins[0];}
            else{
                return 1e9;
            }
        }
        
        int notTake = 0+ helper(coins, amount, ind-1,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take = 1+ helper(coins, amount-coins[ind], ind,dp);
        }
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = helper(coins, amount, n-1,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};
