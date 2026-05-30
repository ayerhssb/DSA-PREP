class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        //TC- O(N) ; SC - O(1)
        int prev=arr[0];
        arr[0] = arr[0]^arr[1];
        
        for(int i=1;i<n-1;i++){
            int xori = arr[i+1]^prev;
            prev = arr[i];
            arr[i]=xori;
        }
        
        arr[n-1] = prev^arr[n-1];
        
        //TC- O(N) ; SC - O(N)
        
        // vector<int> ans(n);
        // ans[0]=arr[0]^arr[1];
        // ans[n-1] = arr[n-2]^arr[n-1];
        // for(int i=1;i<n-1;i++){
        //     ans[i] = arr[i-1]^arr[i+1];
        // }
        // arr=ans;
    }
};
