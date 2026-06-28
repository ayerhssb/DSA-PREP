#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    stack<int> deleteMid(stack<int>& s, int sizeOfStack) {
        stack<int> st;
        int mid = sizeOfStack/2;
        while(mid--){
            st.push(s.top());
            s.pop();
        }
        s.pop();
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        return s;
        
    }
};
