class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int x=nums[i];
            while(x){
                int rem = x%10;
                sum+=rem;
                x=x/10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};
