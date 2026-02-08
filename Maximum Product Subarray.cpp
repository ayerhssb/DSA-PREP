//rev:

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int lmax=INT_MIN,rmax=INT_MIN,lprod=1,rprod=1,n=arr.size();
        if(n==1){return arr[0];}
        for(int i=0;i<n;i++){
            if(lprod==0){lprod=1;}
            lprod*=arr[i];
            lmax=max(lmax,lprod);
        }
        for(int i=n-1;i>=0;i--){
            if(rprod==0){rprod=1;}
            rprod*=arr[i];
            rmax=max(rmax,rprod);
        }
        return max(lmax,rmax);
    }
};


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> &arr){
    ll ans=arr[0], maxprod=arr[0],minprod=arr[0];
    for(int i=1;i<n;i++){
        // if(arr[i]==0){return 0;}
        if(arr[i]<0){swap(maxprod,minprod);}
        maxprod=max(arr[i],arr[i]*maxprod);
        minprod=min(arr[i],arr[i]*minprod);
        ans=max(ans,maxprod);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){cin>>arr[i];}
        ll ans=solve(n,arr);
        cout<<ans<<endl;
    }
    return 0;
}
