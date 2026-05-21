//dfs implementation::

class Solution {
public:
    bool dfs(int n, int node,vector<int> pathvis, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(n,it,pathvis, adj,vis)){return true;}
            }
            else{
                if(pathvis[it]){
                    return true;
                }
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        //BFS:: 

        // vector<vector<int>> adj(n);
        // for(int i=0;i<p.size();i++){
        //     adj[p[i][1]].push_back(p[i][0]);
        // }
        // vector<int> indegree(n);
        // for(int i=0;i<p.size();i++){
        //     indegree[p[i][0]]++;
        // }
        // queue<int> q;
        // for(int i=0;i<indegree.size();i++){
        //     if(indegree[i]==0){
        //         q.push(i);
        //     }
        // }
        // vector<int> topo;
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

        // if(topo.size()!=n){return false;}
        // return true;


        //DFS::

        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
        if(vis[i]==0){if(dfs(n,i,pathvis, adj,vis)){return false;}}}

        return true;
    }
};



//bfs implementation

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> indegree(n);
        for(int i=0;i<p.size();i++){
            indegree[p[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(topo.size()!=n){return false;}
        return true;
    }
};
