class Solution {
public:
    int helper(vector<int>& arr, int d, int idx, vector<int>& dp){
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int result=1;
        //left:
        for(int i=idx-1;i>=max(0,idx-d);i--){
            if(arr[i]>=arr[idx]){break;}
            result = max(result, 1+helper(arr, d, i,dp));
        }

        //right
        for(int i=idx+1;i<=min((int)arr.size()-1, idx+d);i++){
            if(arr[i]>=arr[idx]){break;}
            result = max(result,1+helper(arr, d, i,dp));
        }
        return dp[idx]= result;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size(), ans=0;
        vector<int> dp(n+1,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,helper(arr,d,i,dp));
        }
        return ans;
    }
};
