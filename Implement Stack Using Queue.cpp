#include <bits/stdc++.h>
using namespace std;

class Stack {

public:
    queue<int> q;
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop(); 
    }

    int top() {
        return q.front();
    }

    bool empty() {
        if(q.empty()){return true;}
        return false;
    }

    int size() {
        return q.size();
    }
};
