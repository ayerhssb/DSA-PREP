class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=1e6;
        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){return sum;}
                else if(sum>target){
                    if(abs(sum-target)< abs(ans-target)){
                        ans=sum;
                    }
                    k--;
                }
                else{
                    if(abs(sum-target)< abs(ans-target)){
                        ans=sum;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
