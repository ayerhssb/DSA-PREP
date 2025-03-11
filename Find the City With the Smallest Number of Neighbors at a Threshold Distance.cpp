class Solution {
public:
    void floydwarshall(vector<vector<int>>& mat, int n) {

        for (int i = 0; i < n; i++) {
            mat[i][i]=0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[i][k]==1e9 || mat[k][j] == 1e9){
                        continue;
                    }
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        floydwarshall(mat,n);
        
        int city=-1, cntMax = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (cntMax >= count) {
                cntMax = count;
                city = i;
            }
        }

        return city;
    }
};
