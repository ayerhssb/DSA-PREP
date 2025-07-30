#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};
*/

class solution{
public:
    bool helper(Node* left, Node* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        if(left->data != right->data){return false;}
        return (helper(left->left, right->right) && helper(left->right, right->left));
    }
    bool symmetric(Node* root) {
        if(!root){return true;}
        return helper(root->left, root->right);
    }
};
