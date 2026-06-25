//rev:

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void helper(int idx, int target, int n, vector<int>& arr, vector<int>& temp, set<vector<int>> &st){
        if(idx==n){if(target==0){
            sort(temp.begin(),temp.end());
            st.insert(temp);return;
        }}
        if(target==0){
            sort(temp.begin(),temp.end());
            st.insert(temp);return;
        }
            
        
        for(int i=idx;i<n;i++){
            if(i!=idx && arr[i]==arr[i-1]){continue;}
            temp.push_back(arr[i]);
            helper(i+1,target-arr[i],n,arr,temp,st);
            temp.pop_back();
            // helper(i+1,target,n,arr,temp,st);
        }
    }
    vector<vector<int>> findUniqueCombinations(int n, vector<int>& arr, int target) {
        vector<vector<int>> ans; vector<int> temp;
        set<vector<int>> st;
        sort(arr.begin(),arr.end());
        helper(0, target,n, arr,  temp,st);
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------



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
