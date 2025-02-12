class Solution {
public:
    int sumofdig(int num){
        int sum=0;
        while(num){
            sum += (num%10);
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int maxsum=-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int sumofdigits = sumofdig(nums[i]);
            if(mpp.find(sumofdigits)!=mpp.end()){
                maxsum = max(maxsum, (mpp[sumofdigits]+ nums[i]));
                mpp[sumofdigits] = max(nums[i],mpp[sumofdigits]);
            }
            else{
                mpp[sumofdigits] =nums[i];
            }
            
        }

        return maxsum;
    }
};
