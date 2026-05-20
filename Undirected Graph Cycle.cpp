//revision:

class Solution {
  public:
  
  
  //DFS
bool dfs(vector<vector<int>>& adj, int V, vector<int>& vis, int node, int parent){
    vis[node]=1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(adj, V, vis, it, node)){return true;}
        }
        else{
            if(parent!=it){
                return true;
            }
        }
    }
    return false;
}


//BFS
bool bfs(vector<vector<int>>& adj, int V, vector<int>& vis,int node1){
    queue<pair<int,int>> q;
    q.push({node1,-1});
    vis[node1]=1;
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it, node});
            }
            else{
                if(parent!=it){return true;}
            }
        }
    }
    
    return false;
}

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //for multiple components:
        
        //BFS:
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i] && bfs(adj,V,vis,i)){
        //         return true;
        //     }
        // }
        
        //DFS:
        
        for(int i=0;i<V;i++){
            if(!vis[i]&&dfs(adj,V,vis,i,-1)){
                return true;
            }
        }
        
        return false;
    }
};




//first time


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
