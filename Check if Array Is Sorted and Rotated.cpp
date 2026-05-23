class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0, n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1]){continue;}
            else{cnt++;}
        }
        if(cnt==1&&nums[n-1]>nums[0]){return false;}
        if(cnt>1){return false;}
        return true;
    }
};
