//DFS Solution::

class Solution {
public:
    int delrow[4] = {0,1,0,-1};
    int delcol[4]= {1,0,-1,0};
    void dfs(int n,int m, int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i], newcol=col+delcol[i];
            if(newrow>=0&&newcol>=0&&newrow<n&&newcol<m && !vis[newrow][newcol]){
                if(grid[newrow][newcol]=='1')dfs(n,m,newrow,newcol, grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0,n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(n,m,i, j, grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
