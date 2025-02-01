class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};
