#include<bits/stdc++.h>
using namespace std;


class solution {
public:
    string decimal_to_binary(int n) 
    {
        string str="";
        while(n){
            int rem=n%2;
            str+= (rem+'0');
            n=n/2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
