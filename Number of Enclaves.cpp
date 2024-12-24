class Solution {
public:

    void dfs(int x, int y,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis){
            vis[x][y]=1;

            int delrow[] = {0,0,1,-1};
            int delcol[]= {1,-1,0,0};

            for(int i=0;i<4;i++){
                int nrow=x+delrow[i], ncol=y+delcol[i];
                if(nrow>=0 &&ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    dfs(nrow,ncol,n,m, grid,vis);
                }
            }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), count=0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && vis[0][i]==0){
                dfs(0,i,n,m, grid,vis);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,n,m, grid,vis);
            }
        }

        for(int i=1;i<n-1;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,n,m, grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,n,m, grid,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};
