#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    string retainRareChars(string s, int limit) {
        vector<int> freq(26,0); string ans="";
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']+=1;
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']<limit){
                ans+=s[i];
            }
        }
        return ans;
    }
};
