#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    vector<int> uniqueOrder(int n, vector<int> &arr) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
