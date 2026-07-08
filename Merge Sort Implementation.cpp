#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    void merge(int left, int right, int mid, int arr[]){
        vector<int> temp;
        int l=left,r=mid+1;
        while(l<=mid && r<=right){
            if(arr[l]<arr[r]){temp.push_back(arr[l]); l++;}
            else{temp.push_back(arr[r]);r++;}
        }
        while(l<=mid){
            temp.push_back(arr[l]); l++;
        }
        while(r<=right){
            temp.push_back(arr[r]); r++;
        }
        for(int i=left, j=0;i<=right, j<temp.size();i++, j++){
            arr[i]=temp[j];
        }
    }
    void helper(int left, int right,  int arr[]){
        if(left>=right){
            return;
        }
        int mid=(left+right)>>1;
        helper(left, mid, arr);
        helper(mid+1, right, arr);
        merge(left, right, mid, arr);
    }
    void mergeSort(int arr[], int n){
        helper(0, n-1, arr);
    }
};
