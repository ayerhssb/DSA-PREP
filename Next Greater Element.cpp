#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<int> nextGreaterElement(vector<int> arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        // st.psuh(arr[arr.size()-1]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else{
                ans[i]=-1;
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
