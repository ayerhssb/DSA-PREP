//set approach --> O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int prefixSum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            if(prefixSum == k){
                maxi=max(maxi, i+1);
            }
            else if(mpp.find(prefixSum-k)!=mpp.end()){
                maxi = max(maxi, i-mpp[prefixSum-k]);
            }
            if(mpp.find(prefixSum)==mpp.end()){
                mpp[prefixSum]=i;
            }
        }
        return maxi;
    }
};


//map
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int sum=0,ans=0;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                ans=max(ans,i+1);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            if(mp.find(sum-k)!=mp.end()){
                ans=max(ans,(i-mp[sum-k]));
            }
        }
        return ans;
        
    }
};
