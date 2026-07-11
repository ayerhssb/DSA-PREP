#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    vector<vector<int>> matOperations(vector<vector<int>> matrix) {
        // vector<vector<int>> ans=matrix;
        int m=matrix.size(), n=matrix[0].size();
        int asc=1;
        for(int i=0;i<m;i++){
            vector<int> temp = matrix[i];
            if(asc){sort(temp.begin(), temp.end()); asc=0;}
            else{
               sort(temp.begin(), temp.end(), greater<int>()); asc=1;
            }
            matrix[i]=temp;
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            int asc=1;
            for(int j=0;j<m;j++){
                temp.push_back(matrix[j][i]);
            }
            if(asc){sort(temp.begin(), temp.end());asc=0;}
            else{
                sort(temp.begin(), temp.end(), greater<int>());asc=1;
            }
            for(int k=0;k<m;k++){
                matrix[k][i] = temp[k];
            }
        }
        return matrix;
    }
};
