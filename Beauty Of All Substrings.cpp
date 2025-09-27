#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int beautyOfSubstring(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            vector<int> arr(26,0);
            for(int j=i;j<s.size();j++){
                arr[s[j]-'a'] +=1;
            
                int maxfreq=0, minfreq=INT_MAX;
                for(int it:arr){
                    if(it>0){
                        maxfreq = max(maxfreq,it);
                        minfreq = min(minfreq,it);
                    }
                }
                cnt += (maxfreq-minfreq);
            }
        }
        return cnt;
    }
};
