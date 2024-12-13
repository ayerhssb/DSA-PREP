class Solution {
public:
int maxEle(vector<int>& piles){
    int maxi=-1;
    for(int i=0;i<piles.size();i++){
        if(piles[i]>maxi) maxi= piles[i];
    }
    cout<<maxi<<endl;
    return maxi;
}
long long fn(int mid, vector<int>& piles){
    long long sum=0;
    for(int i=0;i<piles.size();i++){
        sum+= ceil(piles[i]/(double)mid);
        // if(sum>h) return sum;
    }
    // cout<<sum<<endl;
    return sum;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=maxEle(piles);
        // int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long n=fn(mid, piles);
            // if(n==h)return mid;
            if(n<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
