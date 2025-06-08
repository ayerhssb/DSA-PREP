class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, maxcnt=0;
        for(int i=0;i<n;i++){
            if(i>maxcnt){return false;}
            cnt=i+nums[i];
            maxcnt=max(maxcnt,cnt);
        }
        return true;
    }
};
