


//Memorization

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& triangle,int n, vector<vector<int>>& dp ){
        if(row==n-1){
            for(int i=0;i<triangle[n-1].size();i++){
                if(i==col){return triangle[n-1][col];}
            }
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down = triangle[row][col] + helper(row+1,col,triangle,n,dp);
        int diag= triangle[row][col] + helper(row+1,col+1,triangle,n,dp);

        return dp[row][col]= min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=helper(0,0,triangle,n,dp);
        return ans;
    }
};
