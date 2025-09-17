#include <bits/stdc++.h>
using namespace std;
/*
class Node {
public:
    int data; 
    Node* left;
    Node* right;
    
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
};

*/
class solution{
    public:
        void leftTraversal(Node* root, vector<int>& arr){
            if(!root){return;}
            leftTraversal(root->left,arr);
            if(!root->left && !root->right){arr.push_back(root->data);}
            leftTraversal(root->right, arr);
        }
        bool leafSimilar(Node* root1, Node* root2) {
            if(!root1 || !root2){return false;}
            vector<int> arr1, arr2;
            leftTraversal(root1,arr1);
            leftTraversal(root2, arr2);
            if(arr1.size()!=arr2.size()){return false;}
            for(int i=0;i<arr1.size();i++){
                if(arr1[i]!=arr2[i]){
                    return false;
                }
            }
            return true;
            
        }
};
