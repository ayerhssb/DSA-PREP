#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    bool isPrime(int num){
        if(num<=1){return false;}
        for(int i=2;i<num;i++){
            if(num%i==0){return false;}
        }
        return true;
    }
    int sumOfPrimeFibonacci(int n) {
        int sum=0;
        int first=0, second=1;
        for(int i=1;i<n;i++){
            int temp = first + second;
            if(isPrime(temp)){sum+=temp;}
            first=second;
            second=temp;
        }
        return sum;
    }
};
