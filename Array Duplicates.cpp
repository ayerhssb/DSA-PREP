class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(auto it:arr){
            if(mpp.find(it)!=mpp.end()){ans.push_back(it);}
            mpp[it]++;
        }
        return ans;
    }
};
