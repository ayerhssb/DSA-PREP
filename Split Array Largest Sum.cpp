class Solution {
public:
    pair<int,int> maxEl(vector<int>& nums){
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<nums.size(); i++){
            if(maxi<nums[i]) maxi=nums[i];
            sum+=nums[i];
        }
        return {maxi,sum};
    }
    int maxsubarraysum(vector<int>& nums, int mid){
        int sum=0,k=1;
        for(int i=0;i<nums.size(); i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                k++;
            }
        }
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=maxEl(nums).first , high = maxEl(nums).second;

        while(low<=high){
            int mid=(low+high)>>1;
            if(maxsubarraysum(nums,mid)>k)low=mid+1;
            else{high=mid-1;}
        }
        return low;
    }
};
