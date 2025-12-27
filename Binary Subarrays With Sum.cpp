class Solution {
public:
    int fn(vector<int>& nums, int goal){
        if(goal<0){return 0;}
        long long l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){sum-=nums[l];l++;}
            cnt= cnt+ (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=fn(nums,goal)-fn(nums,goal-1);
        return ans;
    }
};
