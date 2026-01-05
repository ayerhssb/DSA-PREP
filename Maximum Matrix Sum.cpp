class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long totalSum=0,smallest=INT_MAX,countNegative=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                totalSum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){countNegative++;}
                if( abs(matrix[i][j])< smallest){smallest =  abs(matrix[i][j]);}
            }
        }
        if(countNegative%2){return (totalSum - 2*smallest);}
        return totalSum;
    }
};
