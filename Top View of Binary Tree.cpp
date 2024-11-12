class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> qu;
        
        qu.push({root, 0});
        
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            Node* node = it.first;
            int line_no = it.second;
            if(mp.find(line_no) == mp.end()) {mp[line_no] = node->data;}
            
            if(node->left) qu.push({node->left, line_no-1});
            if(node->right) qu.push({node->right, line_no+1});
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};