class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long topsum,bottomsum=0;
        long long points = LONG_MAX;
        for(int i=0;i<n;i++){
            topsum += grid[0][i];
        }
        //pp = Partition Point
        for(int pp=0;pp<n;pp++){
            topsum -= grid[0][pp];
            points = min(points,max(topsum,bottomsum));
            bottomsum += grid[1][pp];
        }

        return points;
    }
};
