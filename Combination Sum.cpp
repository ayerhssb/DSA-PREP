class Solution {
public:

    void helper(int ind,int sum, vector<int>& list, int target,vector<vector<int>>& ans, vector<int>& candidates){
        if(sum == target){
            ans.push_back(list);
            return;
        }
        if(sum>target)return;
        
        for(int i=ind ; i<candidates.size();i++){
            list.push_back(candidates[i]);
            sum+=candidates[i];
            helper(i,sum, list, target,ans, candidates);
            list.pop_back();
            sum-=candidates[i];
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        helper(0,0, list, target, ans, candidates);
        return ans;
    }
};
