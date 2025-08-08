class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int left = a.size()-1;
        int right = 0;
        while(left>=0 && right<b.size()){
            if(a[left]>b[right]){
                swap(a[left],b[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};


//revision:

#include <bits/stdc++.h>
using namespace std;
class solution {
public:
    void merge(long arr1[], long arr2[], int n, int m) {
        int p1=n-1,p2=0;
        while(p1>=0 || p2<m){
            if(arr1[p1]>arr2[p2]){
                swap(arr1[p1],arr2[p2]);
                p2++;p1--;
            }
            else{break;}
        }
        sort(arr1,arr1+n);
        sort(arr2, arr2+m);
    }
};
