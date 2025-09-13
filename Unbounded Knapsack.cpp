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
