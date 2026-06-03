#define MOD 1000000007
typedef long long ll;
class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<>());
        int i=0,n=arr.size(),cntzero=0, cntneg=0, maxneg=INT_MIN;
        ll prod=1, prodneg=1; int skipped=false;
        for(int i=0;i<n;i++){
            if(arr[i]<0){cntneg++; maxneg = max(maxneg, arr[i]);}
            else if(arr[i]==0){cntzero++;}
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                continue;
            }
            if(cntneg%2==1 && arr[i]==maxneg && !skipped){
                skipped=true;continue;
            }
            
            // prod = (prod*arr[i])%MOD;
            prod = (prod * ((arr[i] % MOD + MOD) % MOD)) % MOD;
        }
        
        if(cntneg==1&&n==1){
            return arr[0];
        }
        if((cntneg==1&&cntzero==n-1) || cntzero==n){return 0;}
        
        // if(cntneg%2==0){
        //     prod*= prodneg %MOD;
        // }
        // else if(cntneg%2){
        //     prodneg = prodneg/maxneg;
        //     prod=(prod*prodneg)%MOD;
        // }
        return (prod+MOD)%MOD;
    }
};
