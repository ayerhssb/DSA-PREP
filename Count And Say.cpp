
//This is recursive approach --> it uses extra O(n) stack space. 
// Better to use iterative approach, start from n=1 and build the string.

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    string helper(int n){
        if(n==1){
            return "1";
        }
        string s = helper(n-1);
        string ans="";
        int l=0,r=0;
        while(r<s.size()){
            while(s[l]==s[r]){
                r++;
            }
            ans+= ((r-l)+'0');
            ans+=s[l];
            l=r;
        }
        return ans;
    }
    string countAndSay(int n) {
       
       return helper(n);
    }
};
