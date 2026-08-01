
//rev:

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class solution{
public:
    ll power(int mid, int n, int m){
        ll ans=1;
        for(int i=0;i<n;i++){
            ans=ans*mid;
            
            if(ans > m){return m+1;}
        }
        return ans;
    }
    int findNthrootofM (int n, int m){
        int l=1, h=(m/n);
        while(l<=h){
            ll mid= l+ (h-l)/2;
            if(power(mid, n,m) == m){
                return mid;
            }
            if(power(mid,n,m)>m){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};


// ----------------------------------------------------------------------------------------



class Solution {
  public:
  int fn(int mid, int n){
      return pow(mid,n);
  }
    int nthRoot(int n, int m) {
        if(n==1)return m;
        int low=1,high=m;
        while(low<=high){
            int mid=(low+high)/2;
            if(fn(mid,n)==m)return mid;
            if(fn(mid,n)>m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1; 
        
    }
};
