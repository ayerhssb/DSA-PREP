#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int maxInGeneratedSequence(int n){
        vector<int> arr(n);
        arr[0]=0; arr[1]=1;
        for(int i=1;i<n/2;i++){
            arr[2*i]=arr[i];
            arr[2*i+1]=arr[i]+arr[i+1];
        }
        sort(arr.begin(),arr.end());
        return arr.back();
    }
};
