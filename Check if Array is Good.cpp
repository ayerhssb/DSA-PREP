class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            maxi=max(maxi,nums[i]);
        }
        if(nums.size()!=maxi+1){return false;}
        if(mpp[maxi]!=2){return false;}
        for(int i=1;i<mpp.size();i++){
            if(mpp[i]>1){return false;}
        }
        return true;
    }
};
