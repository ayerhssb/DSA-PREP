const long long mod = 1000000007LL;
class Solution {
public:
    long long ncr(long long n){
        if(n<2){return 0;}
        return (1LL * n * (n - 1) / 2) % mod;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int,long long> mpp;
        for(auto &it:points){
            mpp[it[1]]++;
        }
        if(mpp.size()<2){return 0;}
        for(auto &it:mpp){
            long long val=ncr(it.second);
            it.second = val;
        }
        long long ans=0, sum=0;
        for(auto it:mpp){
            long long val=it.second;
            ans=(ans +(val*sum)%mod)%mod;
            sum=(sum+val)%mod;
        }
        
        return (int)(ans%mod);
    }
};
