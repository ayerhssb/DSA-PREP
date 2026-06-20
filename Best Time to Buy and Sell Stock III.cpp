//rev --> forgot

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int helper(int idx, int buy, int k, vector<int>& arr, int n, vector<vector<vector<int>>>& dp){
        if(idx==n || k==0){
            return 0;
        }
        if(dp[idx][buy][k]!=-1){
            return dp[idx][buy][k];
        }
        //perform:
        int profit=0 ;
        if(buy){
           int not_pick = helper(idx+1,1, k, arr, n,dp);
           int pick = helper(idx+1, 0, k, arr,n,dp) - arr[idx];
           profit = max(pick, not_pick);
        }
        else{
            int not_pick = helper(idx+1, 0, k, arr,n, dp);
            int pick = arr[idx] + helper(idx+1, 1, k-1, arr,n, dp);
            profit=max(pick, not_pick);
        }
        return dp[idx][buy][k]=profit;
        
    }
    int maxProfit(vector<int>& arr, int n) {
        //buy = 0, sell = 1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2, arr,n,dp);
    }
};


class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, int n,vector<vector<vector<int>>> &dp){
        if(ind==n){return 0;}
        if(cap==0){return 0;}
        if(dp[ind][buy][cap]!=-1){return dp[ind][buy][cap];}
        if(buy){
            return dp[ind][buy][cap]=max((-prices[ind]+ f(ind+1,0,cap,prices,n,dp)),(0 + f(ind+1,1,cap,prices,n,dp)));
        }
        else{
            return dp[ind][buy][cap]=max((prices[ind]+ f(ind+1,1,cap-1,prices,n,dp)),(0 + f(ind+1,0,cap,prices,n,dp)));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }
};
