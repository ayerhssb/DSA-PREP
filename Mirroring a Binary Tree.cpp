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
class solution{
    public:
    void helper(Node* root){
        if(!root){return;}
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }
    Node* mirrorTree(Node* root) {
        // if(!root){return;}
        helper(root);
        return root;
    }
};
