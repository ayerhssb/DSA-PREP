class Solution {
  public:
    void helper(vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr, int n,int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            // cout<<"it: "<<it<<endl;
            if(!vis[it]){
                arr.push_back(it);
                helper(adj, vis, arr, n, it);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> arr;
        vector<int> vis(n+1,0);
        arr.push_back(0);
        helper(adj,vis,arr,n,0);
        return arr;
    }
};
