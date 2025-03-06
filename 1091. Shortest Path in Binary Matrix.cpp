class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        // if(n==1&&m==1&&grid[0][0]==0){return 1;}
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
        vector<vector<int>> ans(n,vector<int> (m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({1,{0,0}});
        ans[0][0]=1;
        int dist_x[] = {0,0,1,1,1,-1,-1,-1};
        int dist_y[] = {1,-1,0,-1,1,0,-1,1};

        while(!q.empty()){
            int dist = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;

            q.pop();
            for(int i=0;i<8;i++){
                int nr=row+dist_x[i];
                int nc= col+dist_y[i];
                if(nr<n&&nr>=0&&nc<m&&nc>=0&&grid[nr][nc]==0 && dist+1<ans[nr][nc]){
                    ans[nr][nc] = dist+1;
                    q.push({ans[nr][nc],{nr,nc}});
                }
            }
        }
        if(ans[n-1][m-1]==1e9){
            return -1;
        }
        return ans[n-1][m-1];
    }
};
