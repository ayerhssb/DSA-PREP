#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
        int helper(int idx, int mod, vector<int>& arr, vector<vector<int>>& dp){
            if(idx==arr.size()){
                if(mod%2==0){
                    return 0;
                }
                else {
                    return 1;
                }
            }
            if(dp[idx][mod]!=-1){return dp[idx][mod];}
            int ways = helper(idx+1, mod, arr,dp);
            int newmod= (mod+ arr[idx])%2;
            ways = ways + helper(idx+1, newmod, arr,dp);
            return dp[idx][mod] = ways%MOD;
        }
        
    int countOddTotalSubsequences(vector<int>& sequence) {
        int n=sequence.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return helper(0, 0, sequence,dp);
    }
};
