class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,int n, int m,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
        for(int nrow=-1;nrow<=1;nrow++){
            for(int ncol=-1;ncol<=1;ncol++){
                int x=row+nrow, y=col+ncol;
                if(x>=0 && x<n && y>=0 && y<m &&grid[x][y]=='1'&&vis[x][y]!=1){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(),cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
};
