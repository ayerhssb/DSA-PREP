#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int sortStack(stack<int>& st) {
        stack<int> st1; int ans=0;
        while(!st.empty()){
            int num=st.top(); st.pop();
            if(st1.empty()){
                st1.push(num);
            }
            else if(!st1.empty()&&num<st1.top()){
                while(!st1.empty()&& num<st1.top()){
                    st.push(st1.top());st1.pop();
                }
                st1.push(num);
            }
            else{
                st1.push(num);
            }
        }
        
        while(!st1.empty()){
            cout<< st1.top()<< " ";
            st1.pop();
        }
        
        return 0;
        // return ans;
    }
};
