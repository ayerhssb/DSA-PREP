//Memorization
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


//Tabulation

class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp){
        dp[0]= nums[0];
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int not_pick = dp[i-1];

            dp[i] = max(pick,not_pick);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=helper(nums,dp);
        return ans;
    }
};
