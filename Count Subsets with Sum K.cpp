int mod=1e9+7;

int helper(vector<int> nums, int k , int sum, int ind, vector<vector<int>>& dp){
        if(dp[ind][sum]!=-1){return dp[ind][sum];}
        
        if(sum>k||ind==nums.size()){
            if(sum==k){
                return 1;
            }
            return 0;
        }
        int right = helper(nums,k,sum,ind+1,dp);
        int left=0;
        if(sum<=k){
            left = helper(nums,k,sum+nums[ind],ind+1,dp);
        }

        return dp[ind][sum] = (left+right)%mod;
        
    }   	
   

int findWays(vector<int>& arr, int k)
{
        vector<vector<int>> dp(101, vector<int>(10001,-1));
        int ans=helper(arr,k,0,0,dp);
        return ans;
}
