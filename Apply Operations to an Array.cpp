class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> arr;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1]=0;
            }
        }
        int i=0;
        for(auto n:nums){
            if(n!=0){
                nums[i]=n;
                i++;
            }
        }
        while(i<nums.size()){
            nums[i]=0;
            i++;
        }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         cnt++;
        //     }
        //     else{
        //         arr.push_back(nums[i]);
        //     }
        // }
        // while(cnt--){
        //     arr.push_back(0);
        // }
        return nums;
    }
};
