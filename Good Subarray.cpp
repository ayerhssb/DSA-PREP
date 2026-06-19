#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int shortestGoodSubarray(int N, vector<int>& arr) {
        unordered_set<int> st;
        for(auto it:arr){
            st.insert(it);
        }
        if(st.size()<2){
            return -1;
        }
        return 2;
    }
};
