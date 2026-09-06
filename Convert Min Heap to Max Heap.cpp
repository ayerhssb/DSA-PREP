#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    void helper(int i, vector<int>& arr){
        int maxi=i, n=arr.size();
        int left=2*i+1, right=2*i+2;
        if(left<n && arr[left]>arr[maxi]){maxi=left;}
        if(right<n && arr[right]>arr[maxi]){maxi=right;}
        if(maxi!=i){
            swap(arr[maxi], arr[i]);
            helper(maxi, arr);
        }
    }
    void minToMaxHeap(vector<int>& arr) {
        int n=arr.size();
        for(int i=(n/2)-1;i>=0;i--){
            helper(i,arr);
        }
        // priority_queue<int> pq;
        
        // for(auto it:arr){
        //     pq.push(it);
        // }
        // int i=0;
        // while(!pq.empty()){
        //     arr[i]=pq.top();pq.pop();
        //     i++;
        // }
    }
};



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
