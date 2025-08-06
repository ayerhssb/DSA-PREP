#include<bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
*/
class solution {
    public:
    int height(Node* root,int &diff){
        if(!root){return 0;}
        int l=height(root->left,diff);
        int r = height(root->right,diff);
        
        diff = abs(r-l);
        if(diff>1){return -1;}
        return 1+ max(l,r);
    }
    bool balanced (Node* root) {  
        if(!root){return true;}
        int diff =0;
        height(root, diff);
        if(diff ==-1){return false;}
        return true;
   
 
    }
};
