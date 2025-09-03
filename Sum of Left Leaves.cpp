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
    bool isleaf(TreeNode* root){
        if(!root){return false;}
        if(!root->right && !root->left){return true;}
        return false;
    }
    int ans=0;
    void helper(TreeNode* root){
        if(!root){return;}
        if(root->left){
            if(isleaf(root->left)){
                ans+=root->left->val;
            }
        }
        helper(root->left);
        helper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        helper(root);
        return ans;
    }
};
