#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st; vector<int> ans;
        st.push(arr[0]); int i=1;
        while(!st.empty() && i<arr.size()){
            int top=st.top();
            if(arr[i]<0 && top>0){
                if(abs(top)>abs(arr[i])){i++;}
                else if(abs(top)<abs(arr[i])){
                    while(!st.empty() && abs(st.top())<abs(arr[i]) && (arr[i]<0 && st.top()>0)){
                        st.pop();
                    }
                    if(st.empty()){st.push(arr[i]); }
                    else if(abs(st.top())==abs(arr[i])){st.pop();}
                    else if(arr[i]<0 && st.top()<0){
                        st.push(arr[i]);
                    }
                    i++;
                }
                else{st.pop();i++;}
            }else{
                st.push(arr[i]);i++;
            }
        }
        while(i<arr.size()){
            st.push(arr[i]);i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};
