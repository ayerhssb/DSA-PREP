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
    int helper(Node* root, int dir){
        if(!root){return 1;}
        
        if(dir==1 && !root->left && !root->right){
            return root->data;
        }
        int left_prod=1;left_prod = helper(root->left,0);
        int right_prod=1; right_prod= helper(root->right,1);
        return right_prod*left_prod;
    }
    int ProductOfRightLeaves(Node* root) {
        if(!root){
            return 1;
        }
        //dir = 1-->right, 0 -->left;
        if(!root->left && !root->right){return root->data;}
        // if(!root->right){
        //     return 1;
        // }
        // if(!root->left){
        //     return root->right->data;
        // }
        return helper(root,0);
        
    }
};
