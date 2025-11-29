class Solution {
public:
    int findSum(vector<int>& nums){
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        return sum;
    }
    int minOperations(vector<int>& nums, int k) {
        int sum = findSum(nums);
        return sum%k;
    }
};
