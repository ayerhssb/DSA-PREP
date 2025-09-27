#include<bits/stdc++.h>
#include <string>
using namespace std;

class solution {
public:
    bool checkAutomorphicNumber(int num) {
        long long mul = num*num;
        string str1= to_string(mul);
        string str2 = to_string(num);
        for(int i=str2.size()-1, j=str1.size()-1;i>=0;i--,j--){
            if(str1[j]!=str2[i]){return false;}
        }
        return true;
    }

};
