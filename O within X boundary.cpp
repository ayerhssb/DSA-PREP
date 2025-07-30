#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int delrow[4] = {0,0,1,-1};
    int delcol[4] = {1,-1,0,0};
    void dfs(int row, int col, vector<vector<int>>& vis,vector<vector<char>>& grid, int m,int n){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newRow = row+delrow[i];
            int newCol = col + delcol[i];
            if(newRow<m && newCol<n&&newCol>0&&newRow>0&&grid[newRow][newCol]=='O'&& !vis[newRow][newCol]){
                dfs(newRow,newCol,vis,grid,m,n);
            }
        }
    }
    void surroundO(vector<vector<char>>& grid){
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        // delrow
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){dfs(i,0,vis,grid,m,n);}
            if(grid[i][n-1]=='O'){dfs(i,n-1,vis,grid,m,n);}
        }
        for(int i=1;i<n-1;i++){
            if(grid[0][i]=='O'){dfs(0,i,vis,grid,m,n);}
            if(grid[m-1][i]=='O'){dfs(m-1,i,vis,grid,m,n);}
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O' && !vis[i][j]){
                    grid[i][j]='X';
                }
            }
        }
    }
};
