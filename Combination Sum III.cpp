class Solution {
public:
    void helper(int ind, int sum, int k, int n, vector<int>& list,
                vector<vector<int>>& ans, vector<int> arr) {
        if (sum == n) {
            if (list.size() == k) {
                ans.push_back(list);
                return;
            }
        }
        if (sum > n || ind == arr.size()){
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i != ind && arr[i] == arr[i - 1])
                continue;
            list.push_back(arr[i]);
            sum += arr[i];
            helper(i + 1, sum, k, n, list, ans, arr);
            list.pop_back();
            sum -= arr[i];
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> list;
        vector<vector<int>> ans;
        helper(0, 0, k, n, list, ans, arr);
        return ans;
    }
};
