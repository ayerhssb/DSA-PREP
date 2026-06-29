//rev:


#include <bits/stdc++.h>
using namespace std;
/*
class Node {
public:
  int data;
  Node *left, *right;

  Node(int data) {
      this->data = data;
      left = right = nullptr;
  }
};
*/
class solution{
public:
    bool helper(Node* root){
        if(!root){return true;}
        int sum=0;
        if(root->left || root->right){
            if(root->left){sum+=root->left->data;}
            if(root->right){sum+=root->right->data;}
        }
        else{sum=root->data;}
        if(sum != root->data){return false;}
        
        if(!helper(root->left)){return false;}
        if(!helper(root->right)){return false;}
        
        return true;
    }
    bool childrenSumProperty(Node* root) {
        if(!root){return true;}
        return helper(root);
    }
};


// -----------------------------------------------------------------------------------


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
