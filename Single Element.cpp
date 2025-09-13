#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int singleNumber(vector<int> &arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans^=arr[i];
        }
        return ans;
        
    }

};
