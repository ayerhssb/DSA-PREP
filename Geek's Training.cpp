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
