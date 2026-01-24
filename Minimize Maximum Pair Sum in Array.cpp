class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,l=0,n=nums.size();
        int i=0,j=n-1;
        while(i<n/2){
            int sum=nums[i]+nums[j];
            ans=max(ans,sum);
            i++;j--;
            cout<<"ans: "<<ans<<endl;
        }
        return ans;
    }
};
