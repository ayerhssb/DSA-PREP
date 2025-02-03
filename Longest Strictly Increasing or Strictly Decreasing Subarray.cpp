class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans_increasing=0,ans_decreasing=0;
        //for strictly increasing
        int longest=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                longest++;
            }
            else{
                longest=0;
            }
            ans_increasing=max(ans_increasing,longest);
        }
        //for strictly deccreasing
        longest=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                longest++;
            }
            else{
                longest=0;
            }
            ans_decreasing=max(ans_decreasing,longest);
        }
        return max(ans_increasing+1,ans_decreasing+1);
    }
};
