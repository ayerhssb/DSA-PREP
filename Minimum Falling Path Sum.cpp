//Tabulation

class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int mini=1e9;
        for(int i=0;i<n;i++){
           dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j]+ dp[i-1][j];
                int leftdia = matrix[i][j];
                int rightdia = matrix[i][j];
               
                if(j-1>=0){
                    leftdia+= dp[i-1][j-1];
                }
                else{
                    leftdia=1e9;
                }
                if(j+1<n){
                    rightdia+= dp[i-1][j+1];
                }
                else{
                    rightdia=1e9;
                }

                dp[i][j]=min(up,min(rightdia,leftdia));
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};
