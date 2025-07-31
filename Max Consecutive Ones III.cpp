#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int findMaxOnes(vector<int>& arr, int k) {
        int l=0,r=0, zero=0;
        int n=arr.size(), maxLen=0;
        while(r<n){
            if(arr[r]==0){
                zero++;
            }
            while(zero>k){
                if(arr[l]==0){
                    zero--;
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            r++;
        }
        return maxLen;
    }
};
