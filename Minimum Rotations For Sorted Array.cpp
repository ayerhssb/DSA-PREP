#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int minRotations(int arr[], int n){
        int cnt=0, flag=0;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i]){
                return cnt+1;
            }
            cnt++;
        }
        return 0;
    }
};
