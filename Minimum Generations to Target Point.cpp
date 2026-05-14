class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        bool vis[7][7][7] ={};

        int k = 0;
        vector<vector<int>> all;
        for (auto it:points) {
            vis[it[0]][it[1]][it[2]]=1;
            if (it == target) {
                return k;
            }
            all.push_back(it);
        }
        while (true) {
            k++;
            int n=all.size();
            vector<vector<int>> arr;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    vector<int> p1 = {(all[i][0] + all[j][0]) / 2,
                                      (all[i][1] + all[j][1]) / 2,
                                      (all[i][2] + all[j][2]) / 2};
                    if (p1 == target) {
                        return k;
                    } 
                    if(!vis[p1[0]][p1[1]][p1[2]]){
                        vis[p1[0]][p1[1]][p1[2]]=1;
                        arr.push_back(p1);
                    }
                }
            }
            if (arr.size() == 0) {
                break;
            }
            for (auto it : arr) {
                all.push_back(it);
            }
        }
        return -1;
    }
};
