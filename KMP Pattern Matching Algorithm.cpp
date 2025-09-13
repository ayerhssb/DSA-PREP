#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructLPS(string& pattern, vector<int>& lps){
        lps[0]=0;
        int i=1, len=0;
        while(i<pattern.size()){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
        return lps;
    }
    int patternMatching(string text, string pattern) {
        int n=text.size();
        int m=pattern.size();
        vector<int> lps(m);
        constructLPS(pattern,lps);
        int i=0,j=0;
        while(i<n){
            if(text[i]==pattern[j]){
                i++;j++;
                if(j==m){
                    return (i-m);
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};
