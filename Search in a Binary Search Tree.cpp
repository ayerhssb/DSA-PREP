//rev:


#include<bits/stdc++.h>
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
    Node* helper(Node* root, int target){
        if(!root){return nullptr;}
        while(root){
            if(root->data == target){return root;}
            else if(target<root->data){root=root->left;}
            else if(target>root->data){root=root->right;}
        }
        return nullptr;
    }
    Node* search(Node* root, int target) {
        if(!root){return nullptr;}
        return helper(root, target);
    }
};

// -----------------------------------------------------------------------


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
    // TreeNode* search(TreeNode* root, int val){
    //     if(!root){return nullptr;}
    //     if(root->val == val){return root;}
    //     if(root->val > val){search(root->left);}
    //     else{
    //         search(root->right);
    //     }
    //     return nullptr;
    // }
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val == val){return root;}
            if(root->val > val){root=root->left;}
            else{
                // search(root->right, val);
                root=root->right;
            }
        }
        return nullptr;
    }
};
