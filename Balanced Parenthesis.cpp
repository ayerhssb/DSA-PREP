#include<bits/stdc++.h>
using namespace std;
class solution {
public:
    bool balancedParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){st.push(s[i]);}
            else{
                if(st.top()=='(' && s[i]==')'){st.pop();}
                else if(st.top()=='{' && s[i]=='}'){st.pop();}
                else if(st.top()=='[' && s[i]==']'){st.pop();}
                else{return false;}
            }
        }
        return true;
    }
};
