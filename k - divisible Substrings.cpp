#include <bits/stdc++.h>
using namespace std;

class solution {
public:
     int countDivisibleSubstrings(string s, int k) {
         int n=s.size(), ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+= (s[j]-'0');
                if(sum%k==0){ans++;}
            }
        }
        return ans;
    }
};
