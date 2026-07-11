#include <bits/stdc++.h>
using namespace std;

/*class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};*/

class solution {
public:
    // Node* helper(int l, int r,vector<int>& zoneSequence){
    //     if(l>r){return nullptr;}
    //     int mid=(l+r)>>1;
    //     Node* root = new Node(zoneSequence[mid]);
    //     root->left = helper(l, mid-1,zoneSequence);
    //     root->right = helper(mid+1, r, zoneSequence);
    //     return root;
    // }
    // void helper(int idx, int n, vector<int>& zoneSequence, Node* root){
    //     if(idx==n){return;}
    //     if(zoneSequence[idx] > root->data){
    //         root->right = new Node(zoneSequence[idx]);
    //         helper(idx+1, n, zoneSequence, root->right);
    //     }
    //     else{
    //         root->left = new Node(zoneSequence[idx]);
    //         helper(idx+1, n, zoneSequence, root->left);
    //     }
    // }
    int idx=0;
    Node* helper( int low, int high,vector<int>& zoneSequence){
        if(idx== zoneSequence.size()){return nullptr;}
        if(zoneSequence[idx]>high || zoneSequence[idx]<low){return nullptr;}
        Node* node = new Node(zoneSequence[idx]);idx++;
        node->left = helper(low, node->data, zoneSequence);
        node->right = helper(node->data, high, zoneSequence);
        return node;
    }
     Node* buildZoneMap(vector<int>& zoneSequence) {
        int n =zoneSequence.size();
        return helper(INT_MIN, INT_MAX, zoneSequence);
    }
};
