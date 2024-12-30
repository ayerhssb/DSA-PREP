class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mpp;
        for(auto it: a){
            if(mpp[it]==1){continue;}
            mpp[it]++;
        }
        for(auto it:b){
            if(mpp[it]==1){continue;}
            mpp[it]++;
        }
        return mpp.size();
    }
};
