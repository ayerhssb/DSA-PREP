class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<vector<int>> adj;
        unordered_map<int, vector<int>> adj;
        // vector<int> indegree(n,0),ans;
        // queue<int> q;
        for(int i=0;i<graph.size();i++){
            for(int it: graph[i]){
                adj[it].push_back(i);
                // indegree[it]++;
            }
        }

        // int n= adj.size();
        // int indegree[n] = {0};
        vector<int> indegree(n,0);
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

        sort(ans.begin(),ans.end());
        
        return ans; 

    }
};
