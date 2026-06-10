typedef long long ll;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll totalval=0;int n=nums.size(); ll maxval=INT_MIN, minval=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ll maxval=INT_MIN, minval=INT_MAX; ll val=0;
        //     for(int j=i;j<n;j++){
        //         val+=nums[j];
        //         maxval=max<ll>(maxval,nums[j]); 
        //         minval=min<ll>(minval,nums[j]);
        //         totalval = max<ll>(totalval, maxval-minval);
        //     }
        // }
        // return totalval*k;
        for(int i=0;i<n;i++){
            maxval=max<ll>(maxval,nums[i]);
            minval=min<ll>(minval, nums[i]);
        }
        totalval=(maxval-minval);
        return totalval*k;
    }
};
