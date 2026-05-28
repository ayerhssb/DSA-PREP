/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    void helper(unordered_map<int,int>& mpp, int dist, Node* node, int& mn, int& mx){
        if(node==nullptr){
            return;
        }
        helper(mpp,dist-1,node->left,mn,mx);
        mpp[dist]+=(node->data);
        mn=min(mn,dist);
        mx=max(mx,dist);
        helper(mpp,dist+1,node->right,mn,mx);
    }
    vector<int> verticalSum(Node* root) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int mn=0,mx=0;
        helper(mpp,0,root,mn,mx);
        
        for(int i=mn;i<=mx;i++){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};
