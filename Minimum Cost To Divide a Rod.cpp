#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
    int helper(vector<int>& cutPoints, int mini, int maxi, vector<vector<int>> &dp){
        if(cutPoints[maxi]-cutPoints[mini]<=1 || maxi-mini<=1){return 0;}
        if(dp[mini][maxi]!=-1){
            return dp[mini][maxi];
        }
        int mincost = INT_MAX;
        for(int i=mini+1;i<=maxi-1; i++){
            int cost = (cutPoints[maxi]- cutPoints[mini]) + helper(cutPoints, mini, i, dp) + helper(cutPoints, i, maxi, dp);
            mincost = min(mincost, cost);
        }
        return dp[mini][maxi]= mincost;
    }
    int minCostToCutRod(int rodLength, vector<int>& cutPoints) {
        int n=cutPoints.size()+2;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        cutPoints.push_back(0);
        cutPoints.push_back(rodLength);
        sort(cutPoints.begin(), cutPoints.end());
        return helper(cutPoints, 0, cutPoints.size()-1, dp);
    }
};
