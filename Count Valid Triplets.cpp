#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int countTriplets(vector<long long>& arr, int m) {
        int n = arr.size(), cnt=0;
        for(int i=0;i<n;i++){
            unordered_map<int, int> mpp;
            for(int j=n-1;j>i;j--){
                int summod= (arr[i]+arr[j])%m;
                if(summod==0){summod=m;}
                if(mpp.find(m-summod)!=mpp.end()){
                    cnt +=mpp[m-summod];
                }
                int modd = (arr[j])%m;
                mpp[modd]++;
            }
        }
        return cnt;
    }
};
