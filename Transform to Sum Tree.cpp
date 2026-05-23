/* Structure for Tree Node
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
    int helper(Node *node){
        if(node==nullptr){
            return 0;
        }
        int old_data = node->data;
        
        int new_data = helper(node->left)+ helper(node->right);
        
        node->data=new_data;
        
        return new_data+old_data;
    }
    void toSumTree(Node *root) {
        helper(root);
    }
};
