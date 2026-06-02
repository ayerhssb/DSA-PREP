class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int sum=0;
        sort(arr.begin(),arr.end(), greater<>());
        int n=arr.size(),i=0;
        while(i<n-1){
            if(arr[i]-arr[i+1]<k){
                sum+=arr[i+1];sum+=arr[i];
                i+=2;
            }else{
                i++;
            }
        }
        return sum;
    }
};
