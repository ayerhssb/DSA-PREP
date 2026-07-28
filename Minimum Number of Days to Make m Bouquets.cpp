//rev:

#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    bool canmake(int mid, int arr[], int m,int k, int n){
        int bouquet=0, flower=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                flower++;
            }
            else{
                flower=0;
            }
            if(flower==k){bouquet++;flower=0;}
            
        }
        return bouquet>=m;
    }
    int bouquetFormation(int arr[], int n, int k, int m){
        if(n<k*m){
            return -1;
        }
        int maxday=INT_MIN;
        for(int i=0;i<n;i++){
            maxday=max(maxday, arr[i]);
        }
        
        int low=1, high=maxday;
        while(low<=high){
            int mid = (low+high)>>1;
            if(canmake(mid, arr, m, k,n)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return low;
    }
};


class Solution {
public:
    pair<int,int> El(vector<int>& bloomDay){
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        return {mini, maxi};
    }
    bool canMake(vector<int>& bloomDay, int m, int k, int mid){
        int flower=0, bouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                flower++;
            }
            else{
                flower=0;
            }
            if(flower==k){bouquet++; flower=0;}
        }

        if(bouquet>=m){return true;}
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1ll* m * k;
        int n=bloomDay.size();
        if(val>n){return -1;}
        int low=El(bloomDay).first, high=El(bloomDay).second;
        while(low<=high){
            int mid=(low+high)/2;
            if(canMake(bloomDay,m,k,mid)){
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
