#include <bits/stdc++.h>
using namespace std;
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};
*/
class solution {
public:
    int ShortestPath(Node* root) {
        if(!root){return 0;}
        int n=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            n++;
            int s=q.size();
            while(s){
                Node* top=q.front();
                q.pop();s--;
                if(top->left){q.push(top->left);}
                if(top->right){q.push(top->right);}
                if(!top->left && !top->right){return n;}
            }
        }
        return n;
    }
};
