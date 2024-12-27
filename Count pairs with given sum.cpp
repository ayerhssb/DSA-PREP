class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count=0;
        unordered_map<int,int> mpp;
        
        for(int i=0;i<arr.size();i++){
            if(mpp.find(target-arr[i])!=mpp.end()){
                count+=mpp[target-arr[i]];
            }
            mpp[arr[i]]++;
        }
        return count;
    }
};
