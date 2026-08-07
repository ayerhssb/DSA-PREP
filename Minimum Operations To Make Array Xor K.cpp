#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int total_xor=0, cnt=0;
        for(int i=0;i<nums.size();i++){
            total_xor ^= nums[i];
        }
        for(int i=31;i>=0;i--){
            int bit1 = (total_xor>>i)&1;
            int bit2 = (k>>i)&1;
            if(bit1!=bit2){cnt++;}
        }
        return cnt;
    }
};
