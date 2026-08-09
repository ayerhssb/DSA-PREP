#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    vector<int> nextWarmerDays(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n);
        st.push(n-1); ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(temperatures[st.top()]<=temperatures[i]){
                while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                    st.pop();
                }
            }
            if(st.empty()){ans[i]=0;}
            else{
                ans[i] = st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};
