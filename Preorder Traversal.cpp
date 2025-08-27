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
    void preorders(Node* root, vector<int>& ans) {
        if(!root){return;}
        ans.push_back(root->data);
        preorders(root->left,ans);
        preorders(root->right,ans);
    }
    void preorder(Node* root){
        vector<int> ans;
        preorders(root,ans);
        for(int i=0;i<ans.size();i++){cout<< ans[i]<<" ";}
        
    }
};
