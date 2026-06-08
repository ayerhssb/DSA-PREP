class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr;
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                arr.push_back(nums[i]);
            }
            else if(nums[i]==pivot){cnt++;}
        }
        while(cnt--){
            arr.push_back(pivot);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }
};
