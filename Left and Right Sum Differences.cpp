class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n),l(n),r(n);
        l[0]=0;r[n-1]=0;
        for(int i=0;i<n-1;i++){
            l[i+1]=l[i]+nums[i];
        }
        for(int i=n-1;i>0;i--){
            r[i-1]=r[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(l[i]-r[i]);
        }
        return ans;
    }
};
