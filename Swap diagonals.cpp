class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n=mat.size();
        int k=n-1;
        for(int i=0;i<n;i++){
            swap(mat[i][i], mat[i][k]);
            k--;
        }
        
    }
};
