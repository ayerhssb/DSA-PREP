#include <bits/stdc++.h>
using namespace std; 

class solution {
public:
    void helper(string &s, int index,set<string> &ans, string &str){
        if(index == s.size()){
            ans.insert(str);
            return;
        }
        str += s[index];
        helper(s,index+1, ans, str);
        str.pop_back();
        helper(s, index+1, ans, str);
    }
    int countDistinctSubstr(string &s) {  
        set<string> ans;
        // string str;
        // helper(s, 0, ans, str);
        // for(auto it: ans){
        //     cout<< it << " ";
        // }
        
        for(int i=0;i<s.size();i++){
            string str ="";
            for(int j=i;j<s.size();j++){
                str += s[j];
                ans.insert(str);
            }
        }
        return ans.size()+1;
    }

};
