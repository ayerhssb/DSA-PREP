class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        //left : r,c+1 --> down
        //down : r+1,c --> left
        int n=mat.size(), m=mat[0].size();
        int i=0, j=0;
        int dir=0;
        while(true){
            dir = (dir+ mat[i][j])%4;
            
            if(mat[i][j]==1){
                mat[i][j]=0;
            }
            
            if(dir==0){
                j++;
            }
            else if(dir==1){
                i++;
            }
            else if(dir==2){
                j--;
            }
            else if(dir==3){
                i--;
            }
            
            
            if(i<0){
                i++;break;
            }
            else if(i==n){
                i--;break;
            }
            else if(j<0){
                j++; break;
            }
            else if(j==m){
                j--;break;
            }
            
        }
        
        return {i,j};
    }
};
