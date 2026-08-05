#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int dir_x[4]={1,-1, 0,0};
    int dir_y[4]= {0,0,1,-1};
    void helper(int row, int col, int color, int newColor, vector<vector<int>>& image, int m, int n){
        // vis[row][col]=1;
        image[row][col] = newColor;
        for(int i=0;i<4;i++){
            int nr= row+ dir_x[i];
            int nc = col + dir_y[i];
            if(nc>=0&&nc<n && nr>=0 && nr<m && image[nr][nc]==color){
                image[nr][nc] = newColor;
                helper(nr,nc, color, newColor, image,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c,int newColor){
        int m=image.size(), n=image[0].size();
        helper(r, c, image[r][c], newColor, image, m,n);
        return image;
    }
};

// ---------------------------------------------------------------------------------------------------------------


class Solution {
public:
    void dfs(int inCol, int color, int x, int y, int n, int m,
             vector<vector<int>>& image, vector<vector<int>>& ans, int delrow[],
             int delcol[]) {
        ans[x][y] = color;

        for (int i = 0; i < 4; i++) {
            int nrow = x + delrow[i], ncol = y + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                image[nrow][ncol] == inCol && ans[nrow][ncol] != color) {
                dfs(inCol, color, nrow, ncol, n, m, image, ans, delrow, delcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int inCol = image[sr][sc];
        vector<vector<int>> ans = image;

        int delrow[] = {-1, +1, 0, 0};
        int delcol[] = {0, 0, -1, +1};

        dfs(inCol, color, sr, sc, n, m, image, ans, delrow, delcol);

        return ans;
    }
};
