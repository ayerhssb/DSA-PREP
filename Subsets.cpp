class Solution {
public:

    void helper(int ind,vector<int> nums, vector<vector<int>> &ans, vector<int>& list ){
        if(ind >=nums.size()){
            ans.push_back(list);
            return;
        }
        list.push_back(nums[ind]);
        helper(ind+1, nums,ans,list);
        list.pop_back();
        helper(ind+1, nums,ans,list);

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        //using recursion
        vector<vector<int>> ans;
        vector<int> list;
        helper(0,nums, ans,list);
        return ans;

        // using power set


        // int n = nums.size();
        // int subset = (1 << n);
        // vector<vector<int>> ans;
        // for(int i=0;i<subset;i++){
        //     vector<int> list;
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j)){
        //             list.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(list);
        // }
        // return ans;
    }
};
