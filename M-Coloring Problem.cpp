class Solution {
  public:
  
    bool canBeColoured(int node, int col, vector<vector<int>>& adj, vector<int> color, int v){
        for(auto it: adj[node]){
            if(color[it]==col){
                return false;
            }
        }
        return true;
    }
  
    bool helper(int node, vector<int> color, int m, int v, vector<vector<int>> adj){
        if(node==v){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(canBeColoured(node,i,adj,color,v)){
                color[node]=i;
                if(helper(node+1,color,m,v,adj)){return true;}
                else{color[node]=0;}
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(v,0);
        bool res = helper(0,color,m,v,adj);
        return res;
    }
};
