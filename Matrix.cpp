class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int delrow[]={0,0,-1,1};
        int delcol[]= {-1,1,0,0};

        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[x][y]=steps;
            for(int i=0;i<4;i++){
                int nrow=x+delrow[i], ncol=y+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n &&ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return dist;
        
    }
};
