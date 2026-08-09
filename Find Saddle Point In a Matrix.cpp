#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int colcheck(int col, vector<vector<int>>& mat){
        int col_max = INT_MIN;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]> col_max){
                col_max = mat[i][col];
            }
        }
        return col_max;
    }
    int findSaddlePoint(vector<vector<int>>& mat) {
        int n=mat.size(),col=0;
        for(int i=0;i<n;i++){
            int row_min = INT_MAX;
            for(int j=0;j<n;j++){
                if(mat[i][j] < row_min){row_min = mat[i][j]; col=j;}
            }
            if(colcheck(col, mat) == row_min){return row_min;}
        }
        return -1;
    }
};
