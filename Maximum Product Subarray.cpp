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
