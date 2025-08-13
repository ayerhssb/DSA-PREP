/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    int ans=-1;
    while(root){
        
        if(input==root->data){ans=root->data;return ans;}
        if(input>root->data){
            root=root->right;
        }
        else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}
