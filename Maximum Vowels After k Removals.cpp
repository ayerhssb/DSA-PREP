#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int maxVowelsAfterRemovals(string s, int k) {
        int cnt_vowel=0, n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                cnt_vowel++;
            }
        }
        int conso = n- cnt_vowel;
        if(conso>=k){return cnt_vowel;}
        return (cnt_vowel - (k- conso));
    }
};
