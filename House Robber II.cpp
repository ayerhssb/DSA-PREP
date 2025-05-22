//space optimization

class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp){
        // dp[0]=nums[0];
        int prev1=nums[0];
        int prev2=0;

        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1){
                // pick += dp[i-2];
                pick += prev2;
            }
            // int not_pick=dp[i-1];
            int not_pick = prev1;
            // dp[i]=max(pick,not_pick);
            int curr=max(pick,not_pick);
            prev2=prev1;
            prev1=curr;
        }
        // return dp[nums.size()-1];
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size()==1) return nums[0];
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                arr2.push_back(nums[i]);
            }
        }
        int ans1=helper(arr1,dp);
        int ans2=helper(arr2,dp);

        return max(ans1,ans2);
    }
};
