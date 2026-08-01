#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto it:  mpp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
