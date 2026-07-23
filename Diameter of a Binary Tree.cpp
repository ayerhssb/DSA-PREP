#include <bits/stdc++.h>
using namespace std;

/*class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};*/

class solution{
public:
    int helper(Node* root, int &dia){
        if(!root){
            return 0;
        }
        int left= helper(root->left, dia);
        int right = helper(root-> right, dia);
        dia = max(dia, left+right);
        return 1+ max(left, right);
    }
    int diameterOfBinaryTree(Node* root){
        int dia=0;
        helper(root, dia);
        return dia;
    }
};


// ---------------------------------------------------------------------------------------------



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
