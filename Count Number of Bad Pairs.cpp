class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodpairs=0, n = nums.size();
        long long totalpair = (n*(n-1))/2;
        unordered_map<int,int> mpp;
        for(int j=0;j<nums.size();j++){
            if(mpp.find(nums[j]-j)!=mpp.end()){
                goodpairs+= mpp[nums[j]-j];
            }
            mpp[nums[j]-j]++;
        }
        return totalpair-goodpairs;
    }
};
