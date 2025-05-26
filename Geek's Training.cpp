//Space Optimization

int maximumPoints(vector<vector<int>>& arr) {
        
        vector<int> prev(4,0);
        
        prev[0] = max(arr[0][2], arr[0][1]);
        prev[1] = max(arr[0][2], arr[0][0]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][2], max(arr[0][0],arr[0][1]));
        
        for(int i=1;i<arr.size();i++){
            vector<int> temp(4,0);
            for(int j=0;j<4;j++){
                temp[j]=0;
                for(int k=0;k<3;k++){
                    if(k!=j){
                        int activity = arr[i][k]+ prev[k];
                        temp[j] = max(temp[j], activity);
                    }
                }
                
            }
            prev=temp;
        }
        
        
       
        return prev[3];
        
    }

//Tabulation
int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        
        dp[0][0] = max(arr[0][2], arr[0][1]);
        dp[0][1] = max(arr[0][2], arr[0][0]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][2], max(arr[0][0],arr[0][1]));
        
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<4;j++){
                dp[i][j]=0;
                
                for(int k=0;k<3;k++){
                    if(k!=j){
                        int activity = arr[i][k]+ dp[i-1][k];
                        dp[i][j] = max(dp[i][j], activity);
                    }
                }
            }
        }
        
        int maxi=-1e9;
        for(int i=0;i<2;i++){
            maxi = max(maxi, dp[arr.size()-1][i]);
        }
        return maxi;
        
    }

//Memorization

class Solution {
  public:
  
    int f(int days, int last,vector<vector<int>>& arr,vector<vector<int>> &dp ){
        if(dp[days][last]!=-1){return dp[days][last];}
        if(days==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(last!=i){
                    maxi=max(maxi,arr[0][i]);
                }
            }
        return dp[days][last]=maxi;
    }
        
        
        int maxi=0;
        for(int i=0;i<3;i++){
            
            if(last!=i){
                int activity = arr[days][i] + f(days-1,i,arr,dp);
                maxi=max(maxi,activity);
                
            }
            
        }
        return dp[days][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        int maxi=0;
        for(int i=0;i<3;i++){
            maxi=max(maxi,f(arr.size()-1,i,arr,dp));
        }
        
        return maxi;
    }
};
