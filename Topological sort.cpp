lass Solution {
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
