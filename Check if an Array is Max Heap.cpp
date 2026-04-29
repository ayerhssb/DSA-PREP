class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // childern -> 2i+1 and 2i+2
        int n=arr.size();
        for(int i=0;i<n;i++){
            int l=2*i+1, r=2*i+2;
            if(l<n){if(arr[l]>arr[i]){return false;}}
            if(r<n){if(arr[r]>arr[i]){return false;}}
        }
        return true;
    }
};
