/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool helper(Node* root){
        if(root==nullptr){return true;}
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        
        int sum = (!(root->left)?0:root->left->data) + (!(root->right)?0:root->right->data);
        
        if(root->data == sum){return helper(root->left) && helper(root->right);}
        return false;
        
    }
    int isSumProperty(Node *root) {
        if(helper(root)){return 1;}else{return 0;}
        return -1;
    }
};
