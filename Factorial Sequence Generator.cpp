//O(N)

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    // long long helper(long long n){
    //     if(n<=1){return 1;}
    //     return n*helper(n-1);
    // }
    vector<long long> factorialSequence(int n) {
        vector<long long> ans;
        ans.push_back(1);
        for(long long i=2;i<=n;i++){
            ans.push_back(ans.back()*i);
        }
        return ans;
    }
};


//RECURSIVE SOLN --> O(N^2)

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    long long helper(long long n){
        if(n<=1){return 1;}
        return n*helper(n-1);
    }
    vector<long long> factorialSequence(int n) {
        vector<long long> ans;
        for(long long i=1;i<=n;i++){
            ans.push_back(helper(i));
        }
        return ans;
    }
};
