class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        for(auto it: a){
            mpp[it]=1;
        }
        
        for(auto i:b){
            
            if(mpp[i]==1) {mpp[i]=0; ans.push_back(i);}
        }
        return ans;
        
    }
};
