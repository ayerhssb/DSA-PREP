#include <bits/stdc++.h>
using namespace std;

class solution {
public: 
    bool helper(int i, string& s, int count, vector<vector<int>>& dp ){
        if(count<0){
            return false;
        }
        if(i==s.size()){
            if(count==0){return true;}else{return false;}
        }
        if(dp[i][count]!=-1){
            return dp[i][count];
        }
        if(s[i]=='('){
            return dp[i][count] = helper(i+1, s, count+1,dp);
        }
        else if(s[i]==')'){
            return dp[i][count] = helper(i+1, s, count-1,dp);
        }
        return dp[i][count]  = helper(i+1,s,count+1,dp) || helper(i+1,s,count,dp) || helper(i+1,s,count-1,dp); 
    }
    
    bool balancedLocks(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(0,s,0,dp);
    }
};
