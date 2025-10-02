//revision:

#include <bits/stdc++.h>
using namespace std;

/*class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};*/

class Solution {
public:
    vector<int> rightView(Node* root) {
        vector<int> ans;
        if(!root){return ans;}
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node* temp=q.front();
                q.pop();
                
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
        }
        return ans;
    }
};

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
    vector<int> rightSideView(TreeNode* root1) {
        vector<int> ans;
        if(!root1){return ans;}
        queue<TreeNode*> q;
        q.push(root1);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->val);
            while(n--){
                TreeNode* root = q.front();
                q.pop();
                if(root->right)q.push(root->right);
                if(root->left)q.push(root->left);
            }
            
        }
        return ans;
    }
};
