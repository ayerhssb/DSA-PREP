class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(cap+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=cap;k++){
                    if(buy){
                        dp[ind][buy][k] = max(-prices[ind]+ dp[ind+1][0][k], 0+dp[ind+1][1][k]);
                    }
                    else{
                        dp[ind][buy][k] = max(prices[ind]+ dp[ind+1][1][k-1], 0+dp[ind+1][0][k]);
                    }
                } 
            }
        }

        return dp[0][1][cap];

    }
};

//revision:

#include <bits/stdc++.h>
using namespace std;

class solution {
public:    
    int maxProfit(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        dp[i][buy][cap] = max(-arr[i]+dp[i+1][0][cap], 0+dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(arr[i]+dp[i+1][1][cap], 0+dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
        
    }    
};
