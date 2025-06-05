class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<long long> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxi=INT_MIN;
        for(int num: st){
            if(st.find(num-1)!=st.end()){continue;}
            int cnt=1;
            while(st.find(num+1)!=st.end()){
                cnt++;
                num++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
