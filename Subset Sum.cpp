#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    bool helper(int ind, int n, int k, int arr[]){
        if(ind==n || k<0){
            return false;
        }
        if(k==0){return true;}
        return helper(ind+1, n,k,arr) || helper(ind+1, n,k-arr[ind], arr);
    }
    bool subsetSum(int n, int k, int arr[]){
        return helper(0, n,k, arr);
    }
};
