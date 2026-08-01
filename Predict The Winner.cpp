class Solution {
public:
    int helper(vector<int>& nums, int i, int j){
        if(i>j){
            return 0;
        }

        int take_i = nums[i] + min( helper(nums, i+2, j), helper(nums, i+1, j-1));
        int take_j = nums[j] + min(helper(nums, i, j-2), helper(nums, i+1, j-1));

        return max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0;i<n;i++){sum+=nums[i];}
        int p1 = helper(nums, 0, n-1) , p2 = sum-p1;
        if(p2>p1){return false;}
        return true;
    }
};
