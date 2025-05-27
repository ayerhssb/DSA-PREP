class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1, 0));
        
       
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        
        
        
        
        if(arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(arr[i]<=j){
                    take = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take + notTake;
                    
            }
            
        }
        
        return dp[n-1][target];
    }
};
