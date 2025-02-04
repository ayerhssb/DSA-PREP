/*class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  int dia=0;
  int calcheight(Node* root){
      if(root==nullptr){
          return 0;
      }
      int lh = calcheight(root->left);
      int rh = calcheight(root->right);
      
      dia = max(dia, lh+rh);
      return max(lh,rh)+1;
  }
    int diameter(Node* root) {
        calcheight(root);
        return dia;
    }
};
