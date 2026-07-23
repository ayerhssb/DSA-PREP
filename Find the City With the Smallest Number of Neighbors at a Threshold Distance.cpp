//rev:
//Floyd Warshall Algo

#include <bits/stdc++.h>
using namespace std;

class solution {
   public:
    int citySmallestNeighbours(int n, vector<vector<int>>& edges, int maxDistance) {
        // vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            // adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            grid[edges[i][0]][edges[i][1]] = edges[i][2];
            grid[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; i++) {
            grid[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][via]!=INT_MAX && grid[via][j]!=INT_MAX && grid[i][j] > grid[i][via] + grid[via][j]) {
                        grid[i][j] = grid[i][via] + grid[via][j];
                    }
                }
            }
        }
        int ans=0, mincnt=INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt=0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]<=maxDistance) {
                    cnt++;
                }
            }
            if(cnt<=mincnt){
                mincnt=cnt; ans=i;
            }
        }
        return ans;
    }
};


// -------------------------------------------------------------------------------------------------------------------------------------------



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
