/*
struct Node {
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
    
    
    void summ(Node *root, int k,int &count, int currsum, unordered_map<int,int>& mpp){
        if(root==nullptr) {
            return;
        }
        currsum+=root->data;
        if(currsum==k){
            count++;
        }
        if(mpp.find(currsum-k)!=mpp.end()){
            count+=mpp[currsum-k];
        }
        mpp[currsum]++;
        summ(root->left,k,count,currsum,mpp);
        summ(root->right,k,count,currsum,mpp);
        mpp[currsum]--;
    }
    int sumK(Node *root, int k) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        unordered_map<int,int> mpp;
        summ(root,k,count,0,mpp);
        
        return count;
    }
};
