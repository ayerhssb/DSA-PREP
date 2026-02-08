//rev:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root){
        if(!root){return 0;}
        int l= helper(root->left);
        int r=helper(root->right);
        if(l==-1 || r==-1){return -1;}
        if(abs(l-r)>1){return -1;}
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        // if(!root){return true;}
        if(helper(root)==-1){return false;}
        return true;
    }
};




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
