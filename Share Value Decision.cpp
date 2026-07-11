#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    bool ispalindrome(long long x){
        string str = to_string(x);
        int l=0, r=str.size()-1;
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    string shareValue(long long x) {
        string ans;
        if(x<0){
            ans="NO";
        }
        else if(ispalindrome(x)){
            ans="YES";
        }
        else{
            ans="NO";
        }
        return ans;
    }
};
