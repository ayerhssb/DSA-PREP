class Solution {
  public:
    int helper(string& s, int prevSum, int idx, vector<vector<int>>& dp){
        
        if(dp[idx][prevSum]!=-1){
            return dp[idx][prevSum];
        }
        if(idx==s.size()){
            return 1;
        }
        int currSum=0, res=0;
        
        for(int i=idx; i<s.size();i++){
            
            currSum += s[i]-'0';
            if(prevSum<=currSum){
            res+=helper(s,currSum, i+1,dp);}
        }
        
        return dp[idx][prevSum]=res;
    }
    int validGroups(string &s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(9*(s.size()),-1));
        return helper(s, 0,0,dp);
    }
};
