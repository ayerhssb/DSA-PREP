#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void helper(int ind, vector<int>& arr, vector<vector<int>>& ans, vector<int>& list){
        if(ind==arr.size()){ans.push_back(list);return;}
        list.push_back(arr[ind]);
        helper(ind+1,arr,ans,list);
        list.pop_back();
        helper(ind+1,arr,ans,list);
    }
    vector<vector<int>> powerSet(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> list;
        helper(0, arr, ans,list);
        return ans;
    }

};
