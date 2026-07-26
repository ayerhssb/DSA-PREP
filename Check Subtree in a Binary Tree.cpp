#include <bits/stdc++.h>
using namespace std;

/*class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int data) : data(data), left(nullptr), right(nullptr), next(nullptr) {}
};*/

class solution {
   public:
    Node* helper1(Node* root, Node* subroot){
        if(!root){
            return nullptr;
        }
        if(root->data == subroot->data){
            return root;
        }
        Node* left = helper1(root->left, subroot);
        Node* right = helper1(root->right, subroot);
        // if(!left){return nullptr;}
        if(!left && !right){return nullptr;}
        if(left!=nullptr){return left;}
        return right;
    }
    
    bool helper2(Node* subroot, Node* temp){
        if(!subroot && !temp){return true;}
        if(!subroot){return false;}
        if(!temp){return false;}
        if(subroot->data != temp->data){
            return false;
        }
        
        // if(!helper2(subroot->left, temp->left)){return false;}
        // if(!helper2(subroot->right, temp->right)){return false;}
        
        return (helper2(subroot->left, temp->left) && helper2(subroot->right, temp->right));
    }
    bool isSubtree(Node* root, Node* subroot) {
        Node* temp = helper1(root,subroot);
        return helper2(subroot, temp);
        
    }
};
