#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    string strCompression(string s) {
        int n=s.size();
        int i=0; string str;
        while(i<n){
            int cnt=1;
            while(i+1<n && s[i]==s[i+1]){
                cnt++;i++;
            }
            str+=s[i];
            str+= (to_string(cnt));
            
            i++;
        }
        if(str.size()>s.size()){
            return s;
        }
        return str;
    }
};
