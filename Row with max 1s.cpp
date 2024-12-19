class Solution {
  public:
  int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxcnt=0, ind=-1,n=arr.size();
        for(int i=0;i<n; i++){
            int m=arr[i].size();
            int cnt=m-upperBound(arr[i],0,m);
            if(maxcnt<cnt) {maxcnt=cnt; ind=i;}
        }
        
        return ind;
        
    }
};
