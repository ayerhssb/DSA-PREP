class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto it: mpp) {
            if(it.second %2 !=0){
                return false;
            }
        }
        // for (auto it : mpp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        

        return true;
    }
};
