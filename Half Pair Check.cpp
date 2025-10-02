#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasHalf(vector<int>& arr, int n) {
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            if((mpp.find(arr[i]*2)!=mpp.end())){return true;}
            mpp[arr[i]]++;
        }
        return false;
        
    }

};
