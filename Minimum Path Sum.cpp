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
