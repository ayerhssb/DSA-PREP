#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int longestSubstring(string s, int k) {
        if(k==0){return 0;}
        int l=0,r=0,res=0, n= s.size();
        unordered_map<char,int> mpp;
        
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]==1){k-=1;}
            while(k<0){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){k++;}
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    } 
};
