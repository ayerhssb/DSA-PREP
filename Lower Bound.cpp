#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int lowerBound(int arr[], int n, int x) {
        int ans=n;
        for(int i=0;i<n;i++){
            if(arr[i]>=x){
                return i;
            }
        }
        return ans;
    }
};
