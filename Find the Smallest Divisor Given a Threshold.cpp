class Solution {
public:
int maxEl(vector<int>& nums){
    int maxi = INT_MIN;
    for(int i=0;i<nums.size(); i++){
        if(nums[i]>maxi) maxi = nums[i];
    }
    return maxi;
}

int divSum(vector<int>& nums, int mid){
    int sum=0;
    for(int i=0;i<nums.size(); i++){
        sum = sum + ceil(nums[i]/(double)mid);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high = maxEl(nums);
        while(low<=high){
            int mid = (low+high)/2;
            if(divSum( nums, mid)>threshold) {low=mid+1;}
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
