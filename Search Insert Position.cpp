class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, ind;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid]==target){return mid;}
            else if(nums[mid]>target){
                ind=mid;
                high=mid-1;
            }
            else{
                ind=mid+1;
                low=mid+1;
            }
        }
        return ind;
    }
};
