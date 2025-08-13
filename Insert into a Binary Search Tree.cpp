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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp =root;
        TreeNode* temp1;
        if(!root){TreeNode* temp1 = new TreeNode(val); return temp1;}
        while(temp){
            if(temp->val<val){
                if(!temp->right){temp1 = new TreeNode(val);temp->right =temp1; break;}
                temp=temp->right;
            }
            else{
                if(!temp->left){temp1 = new TreeNode(val);temp->left = temp1;break;}
                temp=temp->left;
            }
        }
        // temp = new TreeNode(val);
        return root;
    }
};
