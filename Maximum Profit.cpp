typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    long long getProfit(long long n) {
        ll ans=0, x=0, num=n;
        while(num>0){
            int rem=num%2;
            if(rem==1){
                ll coins = pow(2, x+1) + x * (pow(2, x-1));
                ans+= coins;
            }
            num/=2;x++;
        }
        return ans;
      //greedy --> won't work (was my noob approach)
        // ll ans=0, x=0, num=n;
        // while(num){
        //     num-= pow(2,x);
        //     ll coins = pow(2, x+1) + x * (pow(2, x-1));
        //     ans+= coins;
        //     x++;
        // }
        // return ans;
    }
};
