// revision:
//memoization:

class Solution {
public:
    bool helper(vector<int>& nums, int sum, int idx, int subsum, vector<vector<int>>& dp){
        if(idx==nums.size()){
            return false;
        }
        if(dp[idx][subsum]!=-1){
            return dp[idx][subsum];
        }
        if(idx<nums.size() && subsum== (sum)/2){return true;}
        return dp[idx][subsum]=helper(nums,sum,idx+1,subsum,dp) || helper(nums, sum, idx+1, subsum - nums[idx],dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2){return false;}
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return helper(nums, sum, 0, sum,dp);
    }
};

// Tabulation

class Solution {
public:
    bool helper(vector<int>& arr, int target){
        int n=arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(arr[0]<=target){
            dp[0][arr[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i]<=j){
                    take= dp[i-1][j-arr[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int totSum =0;
        for(int i=0;i<nums.size();i++){
            totSum +=nums[i];
        }
        if(totSum%2 !=0){return false;}
        return helper(nums,totSum/2);
    }
};
