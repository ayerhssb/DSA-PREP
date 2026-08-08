#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int minDeletions(int n, vector<int>& arr) {
        int low=0, high=0;
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                high=i;
            }
            if(arr[i]<mini){
                mini=arr[i];
                low=i;
            }
        }
        int front_low = low+1, front_high = high+1, back_low = n-low, back_high = n-high;
        int ans=INT_MAX;
        ans = min(ans, max(front_high,front_low));
        ans = min(ans, front_low+back_high);
        ans=min(ans, front_high+back_low);
        ans=min(ans, max(back_low,back_high));
        
        return ans;
    }
};
