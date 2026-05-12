class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            int n=nums[i];int fact=n;int mini=fact;
            for(int j=1;j<=sqrt(n);j++){
                if(n%j==0){
                    if(mpp.find(j)!=mpp.end() && mpp.find(n/j)!=mpp.end()){
                        fact=min(j,n/j);
                    }
                    else if(mpp.find(j)!=mpp.end()){fact=j;}
                    else if(mpp.find(n/j)!=mpp.end()){fact=n/j;}
                    mini=min(mini,fact);
                    nums[i]=mini;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
};©leetcode
