class Solution {
  public:
    int helper(int n,vector<int>& dp){
        if(n==0 || n==1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int maxprod =1;
        for(int i=1;i<n;i++){
            int currprod = i * (n-i);
            int recurprod = i* helper(n-i,dp);
            
            maxprod = max(maxprod, max(currprod, recurprod));
        }
        return dp[n]=maxprod;
        
    }
    int maxProduct(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};
