//rev --> but use xor solution

#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int singleNumber(vector<int> &arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }

};


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
