#include<bits/stdc++.h>
using namespace std;

class MyQueue{
public:
    vector<int> arr;
    int t;
    MyQueue(int k){
        t=k;
    //   arr.resize(k); 
    }

    int  push(int x){
        if(arr.size()==t){return -1;}
        arr.push_back(x);
        return x;
    }


    int pop(){
        if(arr.size()==0){return -1;}
        // for(int i=0;i<arr.size()-1;i++){
        //     arr[i]=arr[i+1];
        // }
        int x = arr[0];
        arr.erase(arr.begin()+0);
        return x;
    } 

    int frontElement(){
        if(arr.size()==0){return -1;}
        return arr[0];
    }

    int queueSize(){
       return arr.size();
    }

    bool empty(){
       if(arr.size()==0){return true;}
       return false;
    }

 };
