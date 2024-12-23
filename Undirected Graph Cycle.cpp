class Solution {
  public:
  
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0) {
                if(dfs(it,node,adj,vis)==true){return true;}
            }
            
            else if(it!=parent){
                return true;
            }    
        }
        return false;
    }
//  private:   
    bool bfs(int node,vector<vector<int>>& adj,vector<int>& vis ){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                        return true;
                    
                }
            }
        }
        
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> vis(V,0);
        // vis.push_back({0,-1});
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // if(dfs(i,-1,adj,vis)==true){return true;}
                if(bfs(i,adj,vis)==true){return true;}
            }
        }
        
        return false;
    }
};
