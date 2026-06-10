class Solution {
  public:
    int helper(vector<int>& arr, int l, int r, int left, int right){
        if(l>r){
            return 0;
        }
        int ans=0;
        int mid = (l+r)>>1;
        if(arr[mid]>left && arr[mid]<right){
            ans=1;
        }
        
        int left_ans = helper(arr, l, mid-1, left, min(right, arr[mid]));
        int right_ans= helper(arr, mid+1, r, max(left, arr[mid]), right);
        
        return ans + left_ans + right_ans;
    }
    int binarySearchable(vector<int>& arr) {
        return helper(arr, 0, arr.size()-1, INT_MIN, INT_MAX);
    }
};
