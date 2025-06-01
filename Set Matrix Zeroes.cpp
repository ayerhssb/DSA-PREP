class Solution {
public:
// O(1) Space Complexity 
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int x=1,y=1;
        int n=matrix.size(), m=matrix[0].size();
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                x=0;
                // break;
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                y=0;
                // break;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        //first row iteration
        for(int i=1; i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1; j<m;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }

        if(x==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(y==0){
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }

    }
};




//Another brute approach
void setZeroes(vector<vector<int>>& matrix) {
        // if(matrix.empty()||matrix[0].empty()) return;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> x, y;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        for(int i=0;i<x.size();i++){
            for(int j=0;j<n;j++){
                matrix[x[i]][j] = 0;
            }
        }
        for(int i=0;i<y.size();i++){
            for(int j=0;j<m;j++){
                matrix[j][y[i]] = 0;
            }
        }

}
