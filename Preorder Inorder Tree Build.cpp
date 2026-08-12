#include <bits/stdc++.h>
using namespace std;
/*
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};
*/

class solution {
public:
    int findpos(int n, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==n){
                return i;
            }
        }
        return -1;
    }
    Node* helper(vector<int>& preorder, vector<int>& inorder, int startindex, int endindex, int idx){
        if(startindex>endindex){return nullptr;}
        Node* root = new Node(preorder[idx]);
        int pos = findpos(preorder[idx], inorder);
        root->left = helper(preorder, inorder, startindex, pos-1, idx+1);
        root->right = helper(preorder, inorder, pos+1, endindex, idx+ pos-startindex+1);
        return root;
    }
    Node* buildBinaryTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, inorder.size()-1, 0);
    }
};
