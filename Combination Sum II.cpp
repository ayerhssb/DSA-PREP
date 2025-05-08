class Solution {
public:
    void helper(int ind, int sum, vector<int>& candidates, int target, vector<int>& list, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(list);
            return;
        }
        else if(sum>target){return;}

        for (int i = ind; i < candidates.size(); i++) {
            if (i != ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            list.push_back(candidates[i]);
            
            helper(i+1, sum, candidates, target, list, ans);
            
            sum -= candidates[i];
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        helper(0, 0, candidates, target, list, ans);
        return ans;
    }
};
