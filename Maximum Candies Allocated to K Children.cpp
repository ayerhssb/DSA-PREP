class Solution {
public:
    int maxEl(vector<int>& candies){
        int maxi=INT_MIN;
        for(int i=0;i<candies.size();i++){
            maxi=max(maxi, candies[i]);
        }
        return maxi;
    }
    bool canDistribute(vector<int>& candies, long long k, long long mid){
        long long cnt=0;
        for(int i=0;i<candies.size();i++){
            // if(mid>candies[i]){return false;}
            cnt+= floor(candies[i]/(double)mid);
        }
        if(cnt>=k){return true;}
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1, high=maxEl(candies);
        while(low<=high){
            long long mid=(low+high)/2;
            if(canDistribute(candies, k, mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};
