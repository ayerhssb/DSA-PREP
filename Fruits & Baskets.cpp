#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int fruitsBaskets(vector<int>& tree) {
        unordered_map<int,int> mpp;
        int l=0,r=0, cnt=0;
        while(r<tree.size()){
            mpp[tree[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[tree[l]]--;
                    if(mpp[tree[l]]==0){
                        mpp.erase(tree[l]);
                    }
                    l++;
                }
            }
            cnt = max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};
