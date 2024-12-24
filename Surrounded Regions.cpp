class Solution {
public:

    void dfs(int x,int y,int n, int m, vector<vector<char>>& mat, vector<vector<int>>& vis){
        vis[x][y]=1;

        int delrow[] = {0,0,-1,1};
        int delcol[]= {1,-1,0,0};

        for(int i=0;i<4;i++){
            int nrow=x+delrow[i], ncol=y+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,n,m,mat,vis);
            }
        }


    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,n,m,mat,vis);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1, j,n,m,mat,vis);
            }
        }

        for(int j=1;j<n-1;j++){
            if(!vis[j][0] && mat[j][0]=='O'){
                dfs(j,0,n,m,mat,vis);
            }
            if(!vis[j][m-1] && mat[j][m-1]=='O'){
                dfs(j,m-1,n,m,mat,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }

        // return mat;
    }
};
