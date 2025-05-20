class Solution {
public:
    int helper(vector<int>& nums, int ind, vector<int>& dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick = helper(nums,ind-2,dp) + nums[ind];
        int not_pick = 0+ helper(nums,ind-1,dp);
        return dp[ind]= max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=helper(nums,nums.size()-1,dp);
        return ans;
    }
};
