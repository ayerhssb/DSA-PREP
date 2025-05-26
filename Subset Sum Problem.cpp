//Space Optimization

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1, false));
        
        vector<bool> prev(sum+1, false);
        
        prev[0] = true;
        
        
        if(arr[0]<=sum){
            prev[arr[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            vector<bool> cur(sum+1,false);
            for(int j=1;j<=sum;j++){
                bool notTake = prev[j];
                bool take = false;
                if(arr[i]<=j){
                    take = prev[j-arr[i]];
                }
                
                cur[j] = take || notTake;
                    
            }
            prev=cur;
        }
        
        return prev[sum];
        
    }
};

//Tabulation


class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1, false));
        
        // vector<bool> prev(sum+1, false);
        
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        // prev[0] = true;
        
        
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            // vector<bool> cur(sum+1,false);
            for(int j=1;j<=sum;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i]<=j){
                    take = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take || notTake;
                    
            }
            // prev=cur;
        }
        
        return dp[n-1][sum];
        
    }
};
