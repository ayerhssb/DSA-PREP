/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


//Recursive solution:

class Solution {
  public:
    void helper(Node* root, vector<int>& ans, int n){
        if(!root){return;}
        if(ans.size()==n){
            ans.push_back(root->data);
        }
        
        helper(root->left, ans, n+1);
        helper(root->right, ans,n+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        helper(root,ans,0);
        return ans;
    }
};

//level order

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root){return ans;}
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return ans;
    }
};
