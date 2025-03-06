class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b;
        int n=grid.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mpp.find(grid[i][j])!=mpp.end()){
                    a=grid[i][j];
                }
                mpp[grid[i][j]]++;
            }
        }
        for(int i=1;i<=n*n; i++){
            if(mpp.find(i)==mpp.end()){
                b=i;
                break;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
