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
const long long MOD=1000000007;
typedef long long ll;
class Solution {
public:
    void totSum(TreeNode* root,ll &sum){
        if(!root){return ;}
        sum+=root->val;
        if(root->left){totSum(root->left, sum);}
        if(root->right){totSum(root->right,sum);}
    }
    ll helper(TreeNode* root, ll totsum,ll &ans){
        if(!root){return 0;}
        ll sum = root->val + helper(root->left, totsum,ans) + helper(root->right, totsum,ans);
        if(sum*(totsum-sum)>ans){
            ans = sum*(totsum-sum);
        }
        // cout<<"ans: "<<ans<< " ";
        return sum;
    }
    int maxProduct(TreeNode* root) {
        ll totalSum=0, ans=0;
        totSum(root, totalSum);
        cout<<totalSum<< " ";
        helper(root, totalSum, ans);
        return ans%MOD;
    }
};
