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
    int maxLevelSum(TreeNode* root) {
        int ans=INT_MIN, sum=0,res=0,level=0;
        queue<TreeNode*> q;
        q.push(root);
        // sum+=root->val;ans=max(ans,sum);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            level++;
            while(n){
                TreeNode* top=q.front();
                if(top->left){q.push(top->left);}
                if(top->right){q.push(top->right);}
                n--;q.pop();sum+=top->val;
                cout<<"sum: "<<sum<< " ";
            }
            if(sum>ans){res=level;}
            ans=max(ans,sum);
            // if(ans>=sum){res=level;}
            cout<<"ans: "<<ans<<" "<< res <<endl;
        }
        return res;
    }
};
