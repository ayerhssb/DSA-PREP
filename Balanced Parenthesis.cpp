//used if else:  --> always use stack::

#include<bits/stdc++.h>
using namespace std;


class solution {
public:
    bool balancedParentheses(string s) {
        int curlopen=0, curlclosed=0, roundopen=0, roundclosed=0, squareopen=0, squareclosed=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){roundopen++;}
            else if(s[i]==')'){roundopen--;}
            else if(s[i]=='{'){curlopen++;}
            else if(s[i]=='}'){curlopen--;}
            else if(s[i]=='['){squareopen++;}
            else{squareopen--;}
            
            if(roundopen<0 || squareopen < 0 || curlopen<0){return false;}
        }
        if(roundopen>0 || squareopen > 0 || curlopen>0){return false;}
        return true;
    }
};

// --------------------------------------------------------------------------------------------------------------------

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
