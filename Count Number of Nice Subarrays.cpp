class Solution {
public:
    int fn(vector<int>& nums, int k){
        if(k<0){return 0;}
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            if(nums[r]%2)sum++;
            while(sum>k){if(nums[l]%2){sum-=1;}l++;}
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fn(nums,k)-fn(nums,k-1);
    }
};
