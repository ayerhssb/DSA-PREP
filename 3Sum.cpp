class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1;
            int k = arr.size() - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    // sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                    k--;
                    j++;
                    while (j < k && arr[j] == arr[j - 1]) {
                        j++;
                    }
                    while (j < k && arr[k] == arr[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};


//revision

#include<bits/stdc++.h>
using namespace std;


class solution {
    public:
         vector<vector<int>> threeSum(vector<int>& arr) {
             int n=arr.size();
             sort(arr.begin(),arr.end());
             set<vector<int>> sett;
             
            //  mpp[arr[0]]++;
             vector<vector<int>> ans;
             for(int i=0;i<n-1;i++){
                 if(arr[i]>0){
                     break;
                 }
                 if(i>0 && arr[i]==arr[i-1]){continue;}
                // map<int,int> mpp;
                // for(int j=i+1;j<n;j++){
                //     int target = 0-(arr[i]+arr[j]);
                //     if(mpp.find(target)!=mpp.end()){
                //         vector<int> temp = {arr[i], arr[j], target} ;
                //         sort(temp.begin(),temp.end());
                //         sett.insert(temp);
                //     }
                //     mpp[arr[j]]++;
                // }
                 
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum = arr[i] + arr[j]+ arr[k];
                    if(sum<0){
                        j++;
                    }
                    else if(sum>0){
                        k--;
                    }
                    else{
                        vector<int> temp = {arr[i], arr[j], arr[k]} ;
                        sort(temp.begin(),temp.end());
                        sett.insert(temp);
                        k--; j++;
                        while(j<k && arr[j]==arr[j-1]){j++;}
                        while(j<k && arr[k]==arr[k+1]){k--;}
                    }
                }
             }
             for(auto it: sett){
                 ans.push_back(it);
             }
            return ans; 
        }

};
