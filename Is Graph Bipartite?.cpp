//BFS:


class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int col, vector<int>& color){
        color[node]=col;

        for(auto it: graph[node]){
            if(color[it]==-1){
                if(!dfs(graph, it, !col, color)){return false;}
            }
            else{
                if(color[it]==col){return false;}
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color){
        queue<int> q;
        q.push(node);
        // color[node]=col;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]= !color[node];
                    q.push(it);
                }
                else{
                    if(color[it]==color[node]){return false;}
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        //DFS:
        // for(int i=0;i<graph.size();i++){
        //     if(color[i]==-1){if(!dfs(graph, i, 0, color)){return false;}}
        // }
        // return true;

        //BFS:
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){color[i]=1; if(!bfs(graph, i, color)){return false;}}
        }
        return true;
        
    }
};


//revision:

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int col, vector<int>& color){
        color[node]=col;

        for(auto it: graph[node]){
            if(color[it]==-1){
                if(!dfs(graph, it, !col, color)){return false;}
            }
            else{
                if(color[it]==col){return false;}
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){if(!dfs(graph, i, 0, color)){return false;}}
        }
        return true;
    }
};







class Solution {
public:
    bool dfs(int node,int col, vector<vector<int>>& graph, vector<int> &color){
        color[node]=col;
        for(auto it: graph[node]){
            if(color[it]==-1){
                if(!dfs(it, !col, graph, color)){return false;}
            }
            else if(color[node]==color[it]){
                return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        // vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i, 1, graph, color)){return false;}
            }
        }
        return true;
    }
};
