/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    
    void mirror(Node* root) {
        if(root==NULL){
            return;
        }
        if(root!=nullptr){
            Node* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        
        mirror(root->left);
        mirror(root->right);
    }
};
