#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    // bool isUnique(vector<int>& arr, int l, int r, int k){
    //     set<int> sett;
    //     for(int i=l;i<=r;i++){
    //         sett.insert(arr[i]);
    //     }
    //     if(sett.size()==k){
    //         return true;
    //     }
    //     return false;
    // }
    
    // int noOfUnique(vector<int>& arr, int l, int r, int k){
    //     set<int> sett;
    //     for(int i=l;i<=r;i++){
    //         sett.insert(arr[i]);
    //     }
    //     return sett.size();
    // }
    
    int atMostK(int n, vector<int>& arr, int k){
        int r=0, l=0, ans=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[arr[r]]++;
            if(mpp[arr[r]]==1){
                k--;
            }
            while(k<0){
                mpp[arr[l]]-=1;
                if(mpp[arr[l]]==0){
                    k++;
                }
                l++;
            }
            
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    
    int count_subarrays(int n, vector<int>& arr, int k) {
        return atMostK(n,arr,k) - atMostK(n,arr,k-1);
        // unordered_map<int,int> mpp;
        // int l=0,r=0,cnt=0;
        // while(r>=l){
        //     if(noOfUnique(arr,l,r,k)>k){
        //         l++;
        //     }
        //     else{r++;}
        //     if(isUnique(arr,k,l,r)){cnt++;}
        // }
        
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     vector<int> list;
        //     for(int j=i;j<n;j++){
        //         list.push_back(arr[j]);
        //         if(isUnique(k,list)){cnt++;}
        //     }
        // }
        // return cnt;
    }
};
