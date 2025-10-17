#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool validAnagram(string s1, string s2) {
        if(s1.size()!=s2.size()){return false;}
        unordered_map<char, int> mpp;
        for(char it: s1){
            mpp[it]++;
        }
        for(char it: s2){
            mpp[it]--;
        }
        for(char it:s1){
            if(mpp[it]!=0){return false;}
        }
        return true;
    }

};
