//revision:

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
    void leftNode(Node* root, vector<int>& ans){
        if(!root){return;}
        if(root->left || root->right)ans.push_back(root->data);
        leftNode(root->left,ans);
    }
    void leafNode(Node* root, vector<int>& ans){
        if(!root){return;}
        // ans.push_back(root->left);
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        leafNode(root->left,ans);
        leafNode(root->right,ans);
    }
    void rightNode(Node* root, vector<int>& ans){
        if(!root){return;}
        rightNode(root->right,ans);
        if(root->left || root->right)ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if(!root){return ans;}
        ans.push_back(root->data);
        leftNode(root->left, ans);
        if(root->left|| root->right)leafNode(root,ans);
        rightNode(root->right,ans);
        return ans;
    }
};




vector<int> insertLeftBoundary(TreeNode<int>* root, vector<int>& ans) {

    if (root == nullptr || (!root->left && !root->right)) return ans;

    ans.push_back(root->data);

    if (root->left) insertLeftBoundary(root->left, ans);

    else insertLeftBoundary(root->right, ans);

    return ans;

}

 

vector<int> insertLeaves(TreeNode<int>* root, vector<int>& ans) {

    if (root == nullptr) return ans;

    if (!root->left && !root->right) ans.push_back(root->data);

    insertLeaves(root->left, ans);

    insertLeaves(root->right, ans);

    return ans;

}

 

vector<int> insertRightBoundary(TreeNode<int>* root, vector<int>& ans) {

    if (root == nullptr || (!root->left && !root->right)) return ans;

    if (root->right) insertRightBoundary(root->right, ans);

    else insertRightBoundary(root->left, ans);

    ans.push_back(root->data);

    return ans;

}

 

vector<int> traverseBoundary(TreeNode<int>* root) {

    vector<int> ans;

    if (root == nullptr) return ans;

    ans.push_back(root->data);

    insertLeftBoundary(root->left, ans);

    insertLeaves(root, ans);

    

    insertRightBoundary(root->right, ans);

    return ans;


}
