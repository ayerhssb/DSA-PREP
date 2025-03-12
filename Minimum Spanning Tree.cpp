class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // vector<int> parent(V);
        vector<int> visited(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        // visited[0]=1;
        int sum=0;
        
        while(!pq.empty()){
            int currnode=pq.top().second;
            int edW= pq.top().first;
            pq.pop();
            if(visited[currnode]){
                continue;
            }
            visited[currnode]=1;
            sum+=edW;
            
            for(auto it:adj[currnode]){
                // if(visited[it[0]]){
                //     continue;
                // }
                int adjnode = it[0];
                int wt= it[1];
                
                if(!visited[adjnode]){
                    pq.push({wt,adjnode});
                }
                
            }
        }
        
        return sum;
    }
};
