#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int addTwoNumbers(int a, int b) {
        int result, carry =1;
        while(carry){
            result=a^b; carry= (a&b)<<1;
            a=result;b=carry;
        }
        return result;
    }
};
