class Solution {
public:
int maxEl(vector<int>& nums){
    int maxi = INT_MIN;
    for(int i=0;i<nums.size(); i++){
        if(nums[i]>maxi) maxi = nums[i];
    }
    return maxi;
}
int weightsum(vector<int>& nums){
    int sum=0;
    for(int i=0;i<nums.size(); i++){
        sum+=nums[i];
    }
    return sum;
}

int totalSum(vector<int>& nums, int mid){
    int sum=1, cnt=0;
    for(int i=0;i<nums.size(); i++){
        if((cnt+nums[i])<=mid){
            cnt+=nums[i];
        }
        else{
            cnt = nums[i];
            sum++;
        }
    }
    return sum;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=maxEl(weights), high = weightsum(weights);
        while(low<=high){
            int mid = (low+high)/2;
            if(totalSum( weights, mid)>days) {low=mid+1;}
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
