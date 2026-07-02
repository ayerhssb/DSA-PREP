class Solution {
public:
    void dfs(int node, int timer,int parent, int n,vector<vector<int>> &adj,vector<vector<int>> &ans,vector<int> &vis,vector<int> &disc,vector<int> &low){
        disc[node] = low[node] = timer++;
        vis[node]=1;
        for(auto it: adj[node]){
            if(parent==it){continue;}
            if(!vis[it]){
                dfs(it, timer,node, n, adj, ans, vis, disc, low);
                low[node]=min(low[it], low[node]);
            }
            else{
                low[node]=min(low[node], disc[it]);
            }

            if(low[it]>disc[node]){
                    ans.push_back({node, it});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0], v =connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n,-1);
        vector<int> low(n,-1);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, 0,-1, n, adj, ans, vis, disc, low);
            }
        }
        return ans;
    }
};
