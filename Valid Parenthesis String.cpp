class Solution {
public:
    bool helper(string &s, int ind, int cnt,vector<vector<int>> &dp){
        if(ind>=s.size()){
            return cnt==0;
        }
        if(dp[ind][cnt]!=-1){return dp[ind][cnt];}
        bool ans=false;
        if(s[ind]=='*'){
            ans = ans|| helper(s,ind+1,cnt+1,dp);
            if(cnt){ans = ans|| helper(s,ind+1,cnt-1,dp);}
            ans = ans || helper(s,ind+1,cnt,dp);
        }
        else{
            if(s[ind]=='('){
                ans=helper(s,ind+1,cnt+1,dp);
            }
            else if(cnt){
               ans= helper(s,ind+1,cnt-1,dp);
            }
        }
        return dp[ind][cnt]=ans;
    }
    bool checkValidString(string s) {
        int n=s.size();
            vector<vector<int>> dp(n, vector<int>(n,-1));
            return helper(s,0,0,dp);
       
    }
};
