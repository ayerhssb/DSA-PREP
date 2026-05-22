class Solution {
  public:
  
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int cnt1=0, cntrem1=0;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt1++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                grid[0][i]=0;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                grid[n-1][i]=0;
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=0;
                q.push({i,m-1});
            }
        }
        
        while(!q.empty()){
            auto top=q.front();
            int r=top.first, c=top.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newr=r+delrow[i], newc=c+delcol[i];
                if(newr>=0&&newc>=0&&newr<n&&newc<m&&grid[newr][newc]==1){
                    grid[newr][newc]=0;
                    q.push({newr,newc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cntrem1++;
                }
            }
        }
        return cntrem1;
    }
};
