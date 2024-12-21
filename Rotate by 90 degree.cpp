class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<(n/2);j++){
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
