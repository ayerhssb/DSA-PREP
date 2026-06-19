#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    string decodeString(string s){
        stack<pair<string, int>> st;
        int n=s.size(),i=0;
        int curr_num=0; string curr_str="";
        string ans;
        while(i<n){
            if(isdigit(s[i])){
                curr_num=curr_num*10 +(s[i]-'0');
            }
            else if(s[i]=='['){
                st.push({curr_str, curr_num});curr_str="";curr_num=0;
            }
            else if(s[i]==']'){
                auto top = st.top();
                int k=top.second; ans = top.first; string temp="";
                while(k--){temp+= curr_str;}curr_str=ans+temp;
                st.pop();
            }
            else{
                curr_str+= s[i];
            }
            i++;
        }
        
        return curr_str;
    }
};
