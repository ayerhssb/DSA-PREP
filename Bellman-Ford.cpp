//revision
class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int e=edges.size();
        vector<int> dist(V, 1e8);
        dist[src] =0;
        for(int i=0;i<V;i++){
            bool relaxed =0;
            
            for(auto &it: edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    relaxed=1;
                }
            }
            
            if(!relaxed) break;
        }
        
        for(auto &it: edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                    return {-1};
                }
        }
        
        return dist;
    }
};
