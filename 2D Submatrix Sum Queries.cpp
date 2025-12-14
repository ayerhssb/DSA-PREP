class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        vector<int> ans;
        for(int i=0;i<mat[0].size();i++){
            for(int j=1;j<mat.size();j++){
                mat[j][i]+=mat[j-1][i];
            }
        }
        for(int j=0;j<mat.size();j++){
            for(int k=1;k<mat[0].size();k++){
                mat[j][k]+=mat[j][k-1];
            }
        }
        
        // for(int j=0;j<mat.size();j++){
        //     for(int k=0;k<mat[0].size();k++){
        //         cout<<mat[j][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0], c1=queries[i][1], r2=queries[i][2], c2=queries[i][3],sub=0, sum=0;
            // if(c1!=0){sub = mat[r1][c1-1]+mat[r2][c1-1];}
            sum+= mat[r2][c2];
            if(r1>0){sum-=mat[r1-1][c2];}
            if(c1>0){sum-=mat[r2][c1-1];}
            if(r1>0 && c1>0){sum+=mat[r1-1][c1-1];}
            ans.push_back(sum);
        }
        return ans;
    }
};
