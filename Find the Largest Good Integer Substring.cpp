#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    string largestGoodInteger(string s) {
        string ans;
        int r=1, n=s.size(), num=-1;
        while(r<n-1){
            if(s[r]==s[r-1] && s[r]==s[r+1]){
                if(num<(s[r]-'0')){
                    num=s[r]-'0';
                }
                r=r+2;
            }
            else{r++;}
        }
        
        if(num==-1){return ans;}
        int i=3;
        while(i){
            ans+= (num+'0');
            i--;
        }
        return ans;
    }
};
