#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int maxNestingDepth(string s) {
        int n=0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                st.pop();
            }
            n = max(n, (int)st.size());
        }
        return n;
    }
};
