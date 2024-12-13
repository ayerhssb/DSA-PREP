class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0, high=n-1;
        int ans=arr[low];
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<ans) ans = arr[mid];
            if(arr[mid]>=arr[low]){
                ans = min(ans,arr[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
            
        }
        return ans;
        
    }
};
