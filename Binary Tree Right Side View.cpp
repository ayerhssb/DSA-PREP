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
