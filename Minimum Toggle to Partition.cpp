class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int n=arr.size();
        vector<int> zero(n+1,0);
        // int zero=0;
        for(int i=1;i<n+1;i++){
            if(arr[i-1]==0){
                zero[i]=zero[i-1]+1;
            }
            else{
                zero[i]=zero[i-1];
            }
        }
        // if(zero==0 || zero==n){return 0;}
        int ans=n;
        for(int i=0;i<n+1;i++){
            ans=min(ans,(i-zero[i]) + (zero[n]-zero[i]));
            
        }
        return ans;
    }
};
