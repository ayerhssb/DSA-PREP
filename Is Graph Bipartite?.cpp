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
