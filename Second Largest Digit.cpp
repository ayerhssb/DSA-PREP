#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int secondLargestDigit(int num) {
        int n=num, maxi=INT_MIN, maxi2=INT_MIN;
        while(n){
            int rem=n%10;
            if(rem>maxi){
                maxi2=maxi;
                maxi=rem;
            }
            else if(rem>maxi2 && rem<maxi){
                maxi2=rem;
            }
            n=n/10;
        }
        if(maxi2==INT_MIN){return -1;}
        return maxi2;
    }

};
