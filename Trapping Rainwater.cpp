#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int trapRainwater(vector<int>& arr) {
        int n=arr.size(), totalSum=0;
        vector<int> prefixSum(n,0), suffixSum(n,0);
        prefixSum[0] = arr[0];
        suffixSum[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            prefixSum[i] = max(arr[i], prefixSum[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = max(arr[i], suffixSum[i+1]);
        }
        for(int i=0;i<n;i++){
            totalSum += min(suffixSum[i], prefixSum[i]) - arr[i];
        }
        
        return totalSum;
    }
};
