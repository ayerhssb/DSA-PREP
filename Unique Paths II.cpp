//Tabulation

class Solution {
public:
    int helper(int rows, int col, vector<vector<int>>& dp, int m, int n,
               vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    // return 1;
                    continue;
                }
                if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) {
                    // return 0;
                    dp[i][j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
            if (obstacleGrid[0][0] == 1) {
                return 0;
            } 
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return helper(m - 1, n - 1, dp, m, n, obstacleGrid);
    }
};
