//revision

class Solution {
  public:
  
    void dfs(stack<int>& st, int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(st,it,adj,vis);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // // bfs
        // vector<int> indegree(V);
        // queue<int> q;
        // vector<vector<int>> adj(V); vector<int> topo;
        // for(int i=0;i<edges.size();i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        //     indegree[edges[i][1]]++;
        // }
        
        // //bfs
        // for(int i=0;i<indegree.size();i++){
        //     if(indegree[i]==0){
        //         q.push(i);
        //     }
        // }
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     topo.push_back(node);
        //     for(auto it:adj[node]){
        //         indegree[it]--;
        //         if(indegree[it]==0){
        //             q.push(it);
        //         }
        //     }
        // }
        
        //dfs:
        vector<int> vis(V,0);vector<vector<int>> adj(V);
        stack<int> st;
        vector<int> topo;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
            dfs(st, i,adj, vis);}
        }
        
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
};



class Solution {
  public:
  
    void dfs(int node,int vis[],vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // int n= adj.size();
        // int vis[n] = {0};
        // vector<int> ans;
        // stack<int> st;
        
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i, vis, adj, st);
        //     }
        // }
        
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
        
        //BFS APPROACH
        int n= adj.size();
        int indegree[n] = {0};
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
            ans.push_back(node);
        }
        
        return ans; 
        
    }
};
