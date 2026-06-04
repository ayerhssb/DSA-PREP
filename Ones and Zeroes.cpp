class Solution {
public:
    int helper(vector<string>& strs, int m, int n, int idx,vector<vector<vector<int>>>& dp){
        if(idx==strs.size()){
            return 0;
        }
        if(dp[idx][m][n]!=-1){return dp[idx][m][n];}
        string s=strs[idx];int one=0, zero=0;
        for(auto it: s){
            if(it=='1'){one++;}else{zero++;}
        }
        int take=0;
        if(m-zero>=0 && n-one>=0)take = 1+helper(strs,m-zero, n-one, idx+1,dp);
        int not_take = helper(strs,m, n, idx+1,dp);

        return dp[idx][m][n]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>> dp(l, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return helper(strs,m,n,0, dp);
    }
};
