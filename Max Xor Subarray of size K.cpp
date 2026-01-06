class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int l=0,xorr=0,ans=INT_MIN,len=0;
        for(int i=0;i<arr.size();i++){
            xorr^=arr[i];len++;
            if(len>k){
                xorr^=arr[l];l++;len--;
            }
            if(len==k){ans=max(ans,xorr);}
        }
        return ans;
    }
};
