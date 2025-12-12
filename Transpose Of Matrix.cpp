class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        
        for(int i=0;i<mat.size();i++){
            for(int j=i+1; j<mat[0].size();j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};
