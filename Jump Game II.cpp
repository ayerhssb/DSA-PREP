//Good problem:

class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int> &dp){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int mincnt=INT_MAX;
        for(int i=1;i<=nums[idx] ;i++){
            int x = helper(nums,idx+i,dp);
            if(x!=INT_MAX){mincnt = min(mincnt,1+x);}
        }
        return dp[idx]=mincnt;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,0,dp);
    }
};
