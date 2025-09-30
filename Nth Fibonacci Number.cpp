#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fibNum(int N){
        if(N==1||N==0){return N;}
        return fibNum(N-1)+fibNum(N-2);
    }
};
