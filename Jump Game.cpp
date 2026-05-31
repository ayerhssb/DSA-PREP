//dp:

class Solution {
public:
    bool helper(vector<int>& nums, int idx, vector<int>& dp){
        if(idx>=nums.size()-1){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }

        for(int cnt=1;cnt<=nums[idx];cnt++){
            if(helper(nums,idx+cnt,dp)){dp[idx] = 1;return true;}
        }
        dp[idx]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,dp);
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, maxcnt=0;
        for(int i=0;i<n;i++){
            if(i>maxcnt){return false;}
            cnt=i+nums[i];
            maxcnt=max(maxcnt,cnt);
        }
        return true;
    }
};
