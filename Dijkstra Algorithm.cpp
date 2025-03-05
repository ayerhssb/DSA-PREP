// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n=adj.size();
        vector<int> dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int ,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        q.push({src,0});
        
        while(!q.empty()){
            int currnode = q.top().first;
            int currdist= q.top().second;
            q.pop();
            
            for(auto it:adj[currnode]){
                int edgedist = it.second;
                if(currdist+edgedist<dist[it.first]){
                    dist[it.first] = currdist+edgedist;
                    q.push({it.first, dist[it.first]});
                }
                
            }
        }
        
        for(auto it:dist){
            if(it==1e9){
                it=-1;
            }
        }
        return dist;
    }
};
