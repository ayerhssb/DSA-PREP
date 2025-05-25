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
