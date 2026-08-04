#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool isomorphic(string s1, string s2) {
        unordered_map<char, char> mpp;
        unordered_map<char, char> mpp1;
        int l=0, r=0;
        while(l<s1.size()){
            if(mpp.find(s1[l])!=mpp.end()){
                if(mpp[s1[l]]!=s2[r]){return false;}
            }
            mpp[s1[l]]=s2[r];
            l++;r++;
        }
        l=0,r=0;
        while(r<s2.size()){
            if(mpp1.find(s2[r])!=mpp1.end()){
                if(mpp1[s2[r]]!=s1[l]){return false;}
            }
            mpp1[s2[r]]=s1[l];
            l++;r++;
        }
        return true;
    }

};
