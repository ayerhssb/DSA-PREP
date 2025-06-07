class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxEl;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                maxEl=nums[i];
                cnt=1;
            }
            else if(maxEl!=nums[i]){
                cnt--;
            }
            else{
                cnt++;
            }
        }
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxEl){
                cnt++;
            }
        }
        if(cnt>= (nums.size()/2)){
            return maxEl;
        }
        return -1;
    }
};
