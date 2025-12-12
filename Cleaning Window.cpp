#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countClean(int n, int m, vector<vector<int>> arr){
    vector<vector<int>> ans(n, vector<int>(m,0));
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0;i<m;i++){
        ans[0][i]=1;
        dp[0][i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int res=0;
            if(i-1>=0){
                res=max(res,max(dp[i-1][j] ,arr[i-1][j]));
                if(j-1>=0){res = max(res,max(dp[i-1][j-1], arr[i-1][j-1]));}
                if(j+1<m){res=max(res,max(dp[i-1][j+1], arr[i-1][j+1]));}
                if(res<=arr[i][j]){ans[i][j]=1;}
                dp[i][j]=res;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a;
                cin>>a;
                arr[i][j]=a;
            }
        }
        vector<vector<int>> ans = countClean(n,m,arr);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
