//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind]+ dp[ind+1][0], 0+dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(prices[ind]-fee+dp[ind+1][1], 0+dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};


//Space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2,0));
        vector<int> after(2,0);
        vector<int> curr(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                if(buy){
                    curr[buy] = max(-prices[ind]+ after[0], 0+after[1]);
                }
                else{
                    curr[buy] = max(prices[ind]-fee+after[1], 0+after[0]);
                }
            }
            after=curr;
        }
        return curr[1];
    }
};
