//rev:

#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    string removeOutermostParentheses(string s) {
        int n=s.size(), balance=0;
        string str="";
        stack<char> st; 
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(balance){str+=s[i];}
                balance++;
            }
            else if(s[i]==')'){
                balance--;
                if(balance){str+=s[i];}
            }
        }
        return str;
        
    }

};

// -------------------------------------------------------

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=1;
        string ans;
        for(int i=1;i<s.size();i++){
            if(s[i]=='('){cnt++;}
            else{cnt--;}
            if(cnt>0){
                ans.push_back(s[i]);
            }
            if(cnt==0){cnt=1;i++;}
        }
        return ans;
    }
};
