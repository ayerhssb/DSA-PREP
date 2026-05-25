class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n=arr.size(), total = end-start+1;
        set<int> st;
        for(int i=0;i<n;i++){
            if(arr[i]>=start && arr[i]<=end){
                total--;
            }
        }
        if(total){
            return false;
        }
        return true;
    }
};
