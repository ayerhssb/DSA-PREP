#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int helper(int n, vector<vector<int>> &points, int row, int game, vector<vector<int>>& dp){
        if(row==n){
            return 0;
        }
        if(dp[row][game]!=-1){
            return dp[row][game];
        }
        int sum=points[row][game];
        if(game==2){
            sum += max(helper(n,points, row+1, 0,dp), helper(n, points, row+1, 1,dp));
        }
        else{
           sum +=  max(helper(n,points, row+1, 2,dp), helper(n, points, row+1, !game,dp));
        }
         return dp[row][game]=sum;
    }
    int maxPoints(int n, vector<vector<int>> &points ){
        //r=0, c=1, s=2;
        vector<vector<int>> dp(n+1, vector<int>(3,-1));
        int ans=0;
        for(int i=0;i<3;i++){
            ans=max(ans, helper(n, points, 0, i,dp));
        }
        return ans;
        
    }
};
