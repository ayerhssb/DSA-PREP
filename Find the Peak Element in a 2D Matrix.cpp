class Solution {
  public:
    bool bfs(int row, int col, vector<vector<int>>& mat){
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&&nrow<mat.size()&&ncol>=0&&ncol<mat[0].size()){
                if(mat[nrow][ncol]>mat[row][col]){return false;}
            }
        }
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat){
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(bfs(i,j,mat)){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
