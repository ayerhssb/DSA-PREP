const int mod=1000000007;
class Solution {
public:
    long long fact(int num){
        if(num==0||num==1){
            return 1;
        }
        return (num*fact(num-1))%mod;
    }
    int countPermutations(vector<int>& complexity) {
        int ans=0, n=complexity.size();
        int start=complexity[0];
        unordered_map<int,int> mpp;
        for(int i=1;i<n;i++){
            if(complexity[i]<=start || mpp.find(complexity[i])!=mpp.end()){return 0;}
        }
        ans = fact(n-1)%mod;
        return ans;
    }
};

