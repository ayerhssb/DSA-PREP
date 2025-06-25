/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    void find(Node *root, int pos, int& l, int &r){
        if(!root){
            return;
        }
        l=min(l,pos);
        r=max(r,pos);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    
    void Bview(Node* root, vector<int> &ans, vector<int>& level, int pos, int l){
        if(!root){return;}
        if(level[pos]<=l){
            level[pos]=l;
            ans[pos]=root->data;
        }
        if(root->left){Bview(root->left,ans,level,pos-1,l+1);}
        if(root->right){Bview(root->right,ans,level,pos+1,l+1);}
    }
    vector<int> bottomView(Node *root) {
        // Your Code Here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int> ans(r-l+1);
        vector<int> level(r-l+1,INT_MIN);
        Bview(root, ans,level,-1*l,0);
        return ans;
        
    }
};
