#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    void minToMaxHeap(vector<int>& arr) {
        priority_queue<int> pq;
        
        for(auto it:arr){
            pq.push(it);
        }
        int i=0;
        while(!pq.empty()){
            arr[i]=pq.top();pq.pop();
            i++;
        }
    }
};
