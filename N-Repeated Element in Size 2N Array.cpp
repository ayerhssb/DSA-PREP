// we can do it in o(1) space also by checking any repeated element in a window of three elements. (have to handle len=4 separately)


// o(N/2) space + TC: O(N)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){return nums[i];}
        }
        return -1;
    }
};
