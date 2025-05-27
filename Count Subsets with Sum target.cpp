//Space optimization

int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(),vector<int>(target+1, 0));
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(target+1, 0));
        vector<int> prev(target+1,0);
        vector<int> cur(target+1,0);
        
        prev[0]=1;
        cur[0]=1;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                int notTake = prev[j];
                int take = 0;
                if(arr[i]<=j){
                    take = prev[j-arr[i]];
                }
                
                cur[j] = take + notTake;
                    
            }
            
            prev=cur;
            
        }
        
        return prev[target];
    }
