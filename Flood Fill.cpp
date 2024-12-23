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
