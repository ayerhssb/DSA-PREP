#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> replaceElementsWithRanks(vector<int>& arr) {
          vector<int> ans;
          set<int> st;
          map<int,int> mpp;
          for(int i=0;i<arr.size();i++){
              st.insert(arr[i]);
          }
          int cnt=1;
          for(int it: st){
              mpp[it]=cnt++;
          }
          for(int i=0;i<arr.size();i++){
              int el = mpp[arr[i]];
              arr[i]=el;
          }
        return arr;
    }
};
