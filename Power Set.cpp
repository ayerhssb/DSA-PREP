#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void helper(int idx, vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp){
        
        ans.push_back(temp);
        
        for(int i=idx;i<arr.size();i++){
            temp.push_back(arr[i]);
            helper(i+1, arr, ans, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> powerSet(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, arr, ans, temp);
        return ans;
    }
};


//revision::

class Solution {
  public:
    void helper(string s, vector<string>& ans, int ind, string& str){
        if(ind==s.size()){
            ans.push_back(str);
            return;
        }
        helper(s,ans,ind+1,str);
        str+=s[ind];
        helper(s,ans,ind+1,str);
        str.pop_back();
    }
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        string str="";
        helper(s, ans, 0, str);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


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
