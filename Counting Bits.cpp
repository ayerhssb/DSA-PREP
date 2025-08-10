class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            // ans[i]= __builtin_popcount(i);
            unsigned int cnt=0;
            int num=i;
            while(num){
                // cnt+=(num&1);
                // num>>=1;
                num &= (num-1);
                cnt++;  
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
