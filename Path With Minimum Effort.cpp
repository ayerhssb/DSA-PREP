class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>> q;

        effort[0][0] = 0;
        q.push({0,{0,0}});

        int dist_x[] = {0,0,1,-1};
        int dist_y[] = {1,-1,0,0};

        while(!q.empty()){
            int efforts = -q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(efforts>effort[row][col]){
                continue;
            }
            if(row==n-1 && col==m-1){
                return efforts;
            }

            for(int i=0;i<4;i++){
                int nr = row+dist_x[i];
                int nc=col+dist_y[i];
                if(nc<0||nc>=m||nr<0||nr>=n){
                    continue;
                }
                int new_effort = max(effort[row][col],abs(heights[nr][nc]-heights[row][col]));
                if(new_effort<effort[nr][nc]){
                    effort[nr][nc] = new_effort;
                    q.push({-new_effort,{nr,nc}});
                }
            }
        }
        return effort[n-1][m-1];
    }
};
