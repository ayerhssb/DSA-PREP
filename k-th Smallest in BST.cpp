struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorderTraversal(Node* root, vector<int> &inorder){
        if(root==NULL){
            return;
        }
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        
        if(k>inorder.size()){
            return -1;
        }
        return inorder[k-1];
    }
};
