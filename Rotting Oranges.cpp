class Solution {

private:
    void bfs(vector<int>& rotten_el, vector<vector<int>>& vis, int countfresh,
             int time) {
        int ind1 = rotten_el[0], ind2 = rotten_el[1];
        vis[ind1][ind2] = 1;

        time++;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total=0, time=0, count = 0;
        queue<pair<int, int>> rotten;
        vector<vector<int>> vis;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                if (grid[i][j] != 0)
                    total++;
            }
        }

        while (!rotten.empty()) {
            int k = rotten.size();
            count += k;
            while (k--) {
                int ind1=rotten.front().first, ind2=rotten.front().second;
                rotten.pop();
                vector<int> del_row = {1, 0, -1, 0};
                vector<int> del_col = {0, 1, 0, -1};

                for (int i = 0; i < 4; i++) {
                    int nrow = del_row[i] + ind1, ncol = del_col[i] + ind2;

                    if (nrow < grid.size() && nrow >= 0 && ncol >= 0 &&
                        ncol < grid[0].size() && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        rotten.push({nrow,ncol});
                    }
                    else{
                        continue;
                    }
                }

            }
            if(!rotten.empty()){
                time++;
            }
        }

        if (count != total)
            return -1;

        return time;
    }
};
