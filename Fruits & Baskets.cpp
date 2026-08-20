//rev::

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0, num=2,ans=INT_MIN;
        unordered_map<int,int> mpp;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                int n=fruits[l];
                while(fruits[l]==n){mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){mpp.erase(fruits[l]);}  
                l++;}
            }
            ans=max(ans, r-l+1);
            // if(mpp.find(fruits[r])==mpp.end()){mpp[fruits[r]]++;}
            r++;
        }
        return ans;
    }
};

// ------------------------------------------------------------------------------------------


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
