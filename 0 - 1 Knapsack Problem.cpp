// 0/1 Knapsack Problem

//revision: memoization:
class Solution {
  public:
    int helper(int W, vector<int> &val, vector<int> &wt, int idx, vector<vector<int>>& dp){
        
        if(idx==val.size()-1){
            if(wt[idx]<=W){
                return val[idx];
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
        if(wt[idx]<=W){take = val[idx]+helper(W-wt[idx], val, wt, idx+1,dp);}
        
        return dp[idx][W]=max(take, not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        return helper(W, val, wt,0, dp);
    }
};

//revision
//Space Optimization
int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int> prev(w+1,0), cur(w+1,0);
        for(int i=0;i<=w;i++){
            if(wt[0]<=i){
                prev[i] = val[0];
            }
            else{
                prev[i] = 0;
            }
        }
         for(int i=1;i<n;i++){
             for(int j=0;j<=w;j++){
                int notTake = prev[j];
                int take = 0;
                if(wt[i]<=j){
                    take = val[i]+ prev[j-wt[i]];
                }
                
                cur[j] = max(take, notTake);
             }
             
             prev = cur;
         }
         
         return prev[w];
    }




//Tabulation

int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n, vector<int>(w+1,0));
        
        
        for(int i=0;i<=w;i++){
            if(wt[0]<=i){
                dp[0][i] = val[0];
            }
            else{
                dp[0][i] = 0;
            }
        }
         
         for(int i=1;i<n;i++){
             for(int j=0;j<=w;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(wt[i]<=j){
                    take = val[i]+ dp[i-1][j-wt[i]];
                }
                
                dp[i][j] = max(take, notTake);
             }
         }
         
         return dp[n-1][w];
    }





//Memoization

class Solution {
  public:
    int helper(int w, vector<int> &val, vector<int> &wt, int ind, vector<vector<int>> &dp, int n){
        if(ind==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][w]!=-1 ){return dp[ind][w];}
        int notTake = helper(w, val, wt, ind-1,dp,n);
        int take = 0;
        if(wt[ind]<=w){
            take = val[ind]+ helper(w-wt[ind], val, wt, ind-1,dp,n);
        }
        
        return dp[ind][w]=max(take, notTake);
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n, vector<int>(w+1,-1));
        
        int ans= helper(w, val, wt, n-1,dp,n);
        return ans;
    }
};
