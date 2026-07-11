#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int minSwaps(vector<int>& arr) {
        int swap1=0;
        vector<int> temp=arr;
        sort(begin(temp), end(temp));
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[temp[i]]=i;
        }
        int i=0;
        while(i<arr.size()){
            if(mpp[arr[i]]==i){
                i++;
            }
            else{
                int correctIndex = mpp[arr[i]];
                swap(arr[i], arr[correctIndex]);
                swap1++;
            }
        }
        return swap1;
    }
};
