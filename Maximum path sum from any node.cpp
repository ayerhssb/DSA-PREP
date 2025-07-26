// Revised

/*
// Tree Node
class Node {
public:
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
    int maxsum(Node* root, int &maxi){
        if(root==nullptr){
            return 0;
        }
        
        int maxleftsum = max(0,maxsum(root->left, maxi));
        int maxrightsum = max(0, maxsum(root->right, maxi));
        
        maxi = max(maxi, (maxleftsum+maxrightsum + root->data));
        
        return max(maxleftsum, maxrightsum) + root->data;
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        maxsum(root,maxi);
        
        return maxi;
    }
};
