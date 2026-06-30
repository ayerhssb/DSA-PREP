//rev:

#include <bits/stdc++.h>
using namespace std;
class solution {
public:
    int assignCookies(vector<int>& greed, vector<int>& sizes) {
        int n=greed.size(), m=sizes.size();
        sort(greed.begin(), greed.end());
        sort(sizes.begin(),sizes.end());
       int cnt=0, i=0,j=0;
        while(i<n&&j<m){
            if(greed[i]<=sizes[j]){
                cnt++;i++;j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};


// -------------------------------------------------------------------------------

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, r=0, cnt=0;
        while(l<g.size() && r<s.size()){
            if(s[r]>=g[l]){
                cnt++;r++;l++;
            }
            else{
                r++;
            }
        }
        return cnt;
    }
};
