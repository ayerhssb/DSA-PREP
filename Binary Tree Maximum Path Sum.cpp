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
    int helper(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }
        int lsum = max(0,helper(root->left, ans));
        int rsum = max(0,helper(root->right,ans));
        ans = max(ans, root->val + rsum + lsum);
        return max(lsum,rsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        helper(root,ans);
        return ans;
    }
};
