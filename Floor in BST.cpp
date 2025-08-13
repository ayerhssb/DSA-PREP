// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        int ans=-1;
        while(root){
            if(x==root->data){ans=root->data;return ans;}
            if(x>root->data){
                ans=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return ans;
    }
};
