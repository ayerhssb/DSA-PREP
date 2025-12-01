typedef long long ll;
class Solution {
public:
    pair<ll,ll> el(vector<int> batteries, int n){
        ll low=INT_MAX, high=0;
        for(int i=0;i<batteries.size();i++){
            if(batteries[i]<low){
                low=batteries[i];
            }
            high+=batteries[i];
        }
        high=high/n;
        return {low,high};
    }
    bool canRun(ll mid, vector<int>& batteries, int n){
        ll time=0,comp=n;
        for(auto it:batteries){
            if(it>=mid){
                comp--;
            }
            else{
                time+=it;
            }
        }
        return time>=(comp*mid);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        if(n>batteries.size()){return 0;}
        // if(n==batteries.size()){
        //     return el(batteries).first;
        // }
        // ll ans;
        ll low=0;
        ll high=el(batteries, n).second;
        while(low<high){
            ll mid = (low+high+1)>>1;
            if(canRun(mid, batteries,n)){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
