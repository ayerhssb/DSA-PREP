//rev:

typedef long long ll;
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int shortestJobFirst(vector<int> &d) {
        int n=d.size();
        ll ans=0,total=0;
        sort(d.begin(),d.end());
        for(int i=0;i<n-1;i++){
            ans+=d[i];
            total = total+ans;
        }
        return (total/n);
    }
};
// -------------------------------------------------

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int waitTime=0;
        int t=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size();i++){
            waitTime+=t;
            t+=bt[i];  
        }
        return waitTime/bt.size();
    }
};
