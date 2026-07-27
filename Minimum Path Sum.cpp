//rev:

#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    int helper(vector<vector<int>> &grid, int row, int col,int m, int n,vector<vector<int>> &dp){
        if(row==m-1 && col==n-1){
            return grid[m-1][n-1];
        }
        if(row>=m || col>=n ){
            return INT_MAX;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int right =  helper(grid, row, col+1,m,n,dp);
        int down =  helper(grid, row+1, col,m,n,dp);
        return dp[row][col]=grid[row][col] + min(down,right);
    }
    int minimumPath(int m, int n, vector<vector<int>> &grid){
        // vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        // return helper(grid, 0,0,m,n,dp);
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){
            dp[i][n]=INT_MAX;
        }
        for(int i=0;i<=n;i++){
            dp[m][i]=INT_MAX;
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[m-1][n-1] = grid[m-1][n-1];continue;
                }
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};

// --------------------------------------------------------------------------------------------------


//Tabulation

class Solution {
public:
    int helper(int row, int col, int m, int n, vector<vector<int>>& grid,
               vector<vector<int>>& dp) {
        if (row == 0 && col == 0)
            dp[0][0] = grid[0][0];
        int up = 0, left = 0;

        return dp[m - 1][n - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int up = grid[i][j];
                    if (i > 0) {
                        up += dp[i - 1][j];
                    } else {
                        up = 1e9;
                    }
                    int left = grid[i][j];
                    if (j > 0) {
                        left += dp[i][j - 1];
                    } else {
                        left = 1e9;
                    }
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};



//Memorization

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row==0 && col==0){
            return grid[0][0];
        }
        if(row<0 || col<0){
            return 1e9;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int up=0, left=0;
        up = grid[row][col] + helper(row-1,col,grid,dp);
        left = grid[row][col] + helper(row, col-1,grid,dp);

        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int ans = helper(m-1,n-1,grid,dp);
        return ans;
    }
};
