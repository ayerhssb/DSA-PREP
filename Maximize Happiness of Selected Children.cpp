typedef long long ll;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans=0,cnt=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        for(int i=0;i<k;i++){
            if(happiness[i]-cnt<=0){break;}
            ans+=(happiness[i]-cnt);
            cnt++;
        }
        return ans;
    }
};
