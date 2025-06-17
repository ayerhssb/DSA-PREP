class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int ans=INT_MAX, ind=0;
        
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){if(nums[low]<ans){
                ind=low;
                ans=min(ans, nums[low]);
                } break;}
            if(nums[mid]>=nums[low]){
                if(nums[low]<ans){
                ind=low;
                ans=min(ans, nums[low]);
                }
                low=mid+1;
            }
            else{
                if(nums[mid]<ans){
                ind=mid;
                ans=min(ans, nums[mid]);
                }
                high=mid-1;
            }
        }
        return ind;
    }
};
