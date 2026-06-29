#include <bits/stdc++.h>
using namespace std;

class solution {
public:
   int minCostToJoinRods(vector<int>& arr) {
        // min heaps
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
                int top1 = pq.top(); pq.pop();
                int top2 = pq.top();pq.pop();
                int sum1=(top1+top2);
                sum+= sum1;
                pq.push(sum1);
        }
        
        return sum;
    }
};




#include <bits/stdc++.h>
using namespace std;

class solution {
public:
   int minCostToJoinRods(vector<int>& arr) {
        int tsum=0, n=arr.size();
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            int sum=top1+top2;
            pq.push(sum);
            tsum+=sum;
        }
        return tsum;
        
    }
};
