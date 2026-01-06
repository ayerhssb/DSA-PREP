class Solution {
  public:
    int maxSubarraySum(vector<int> &arr, int k) {
        // code here
        int l=0,sum=0,ans=INT_MIN;
        int len=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];len++;
            if(len>k){
                sum-=arr[l];l++;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};
