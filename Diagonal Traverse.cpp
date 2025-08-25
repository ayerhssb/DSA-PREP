class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mpp;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<mpp.size();i++){
            for(auto it: mpp[i]){
                    cout<<it<< " ";
            }
            cout<<endl;
        }
        
        for(int i=0;i<mpp.size();i++){
            if(i%2==0){
                reverse(mpp[i].begin(), mpp[i].end());
                for(auto it: mpp[i]){
                    ans.push_back(it);
                }
            }
            else{
                for(auto it: mpp[i]){
                    ans.push_back(it);
                }
            }
        }

        return ans;
    }
};
