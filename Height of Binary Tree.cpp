/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        int height=-1;
        queue<Node*> q;
        
        q.push(node);
        while(!q.empty()){
            int k=q.size();
            while(k--){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            height++;
        }
        
        
        return height;
    }
};
