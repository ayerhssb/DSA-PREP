//revision::
//memoization:
class Solution {
  public:
    int helper(int W, vector<int> &val, vector<int> &wt, int idx, vector<vector<int>>& dp){
        
        if(idx==val.size()-1){
            if(wt[idx]<=W){
                return (W/wt[idx])*val[idx];
            }
            else{return 0;}
        }
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }
        //not_take
        int not_take = helper(W, val, wt, idx+1,dp);
        //take 
        int take=0;
        if(wt[idx]<=W){take = val[idx]+helper(W-wt[idx], val, wt, idx,dp);}
        
        return dp[idx][W]=max(take, not_take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        return helper(W, val, wt,0, dp);
    }
};


// -------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        return (a.second/(double)a.first)>(b.second/(double)b.first);
    }
    int helper(int ind, int capacity, vector<int>& wt, vector<int>& profits, vector<vector<int>>& dp){
        if(ind==wt.size()){
            return 0;
        }
        if(dp[ind][capacity]!=-1){return dp[ind][capacity];}
        int take=0;
        if(capacity>=wt[ind])take = profits[ind]+ helper(ind,capacity-wt[ind],wt,profits,dp);
        int notTake=helper(ind+1,capacity,wt,profits,dp);
        return dp[ind][capacity] = max(take,notTake);
    }
    int unboundedKnapsack(vector<int>& wt, vector<int>& profits, int capacity) {
        // vector<pair<int,int>> arr;
        int ans=0;
        vector<vector<int>> dp(wt.size(), vector<int>(capacity+1,-1));
        // for(int i=0;i<wt.size();i++){
        //     arr.push_back({wt[i], profits[i]});
        // }
        // sort(arr.begin(),arr.end(),comp);
        // for(int i=0;i<weights.size();i++){
        //     cout<< arr[i].first << " "<<arr[i].second<<endl;
        // }
        return helper(0,capacity,wt,profits,dp);
    }
};
