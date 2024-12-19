class Solution {
  public:
    int upperBound(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1, ans=n;
        while(low<=high){
            int mid = (low+high)>>1;
            // if(arr[mid]<k)ans= min(ans,arr[mid]);
            if(arr[mid]>k){
                ans= mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int noOfSmallEl(int mid,vector<vector<int>> &mat,int n){
        int sum=0;
        for(int i=0; i<n;i++){
            sum+=upperBound(mat[i],mid);
        }
        return sum;
    }
    int median(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size();
        int low=INT_MAX, high=INT_MIN;
        
        for (int i = 0; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
        }
        int req= (n*m)/2;
        while(low<=high){
            int mid=(low+high)>>1;
            int numsmall = noOfSmallEl(mid,mat,n);
            // if(numsmall == (n*m)/2)return mid;
            if(numsmall <= req){low=mid+1;} 
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
