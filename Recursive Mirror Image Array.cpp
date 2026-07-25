#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    //recursive fn:
        bool helper(vector<int> &arr, int l, int r){
            if(l>=r){
                return true;
            }
            if(arr[l]!=arr[r]){
                return false;
            }
            return helper(arr, l+1, r-1);
        }
    bool isMirrorImage(vector<int>& arr, int n){
        //iterative : 
        
        // int l=0, r=arr.size()-1;
        // while(l<=r){
        //     if(arr[l]!=arr[r]){
        //         return false;
        //     }
        //     l++;r--;
        // }
        // return true;
        return helper(arr,0,arr.size()-1);
        
    }
};
