class Solution {
public:

    bool isvalid(int r, int c, int n, int m){
        return (r>=0 && c>=0 && r<n && c<m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> height(n, vector<int>(m));
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({{i,j},0});
                    visited[i][j] =1;
                }
            }
        }

        while(!q.empty()){
            // int front = q.front();
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int level = q.front().second;
            q.pop();

            int dx[4] = {0,0,-1,1};
            int dy[4] = {-1,1,0,0};

            for(int i=0;i<4;i++){
                int nrow =r + dx[i];
                int ncol = c + dy[i];
                if(isvalid(nrow,ncol,n,m) && !visited[nrow][ncol]){
                    height[nrow][ncol] = level+1;
                    q.push({{nrow,ncol},level+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return height;

    }
};
