#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int reverseNumber(int N) {
        int num=0;
        while(N){
            int rem=N%10;
            num = num*10+rem;
            N=N/10;
        }
        return num;
    }
};
