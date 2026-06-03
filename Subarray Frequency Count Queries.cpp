class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size(), q=queries.size();
        vector<int> ans(q);
        unordered_map<int, vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        for(int i=0;i<q;i++){
            int l=queries[i][0], r=queries[i][1], x=queries[i][2], len=0;
            if(mpp.find(x)!=mpp.end()){
             auto it = mpp[x];
             sort(it.begin(), it.end());
             auto lb = lower_bound(it.begin(), it.end(), l);
             auto ub = upper_bound(it.begin(), it.end(), r);
             len = ub-lb;}
             
             ans[i]=len;
        }
        return ans;
    }
};
