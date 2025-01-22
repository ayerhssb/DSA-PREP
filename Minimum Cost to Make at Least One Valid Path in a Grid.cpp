#define pip pair<int, pair<int,int>>
class Solution {
    bool isvalid(int r, int c, int n, int m){
        return (r>=0 && c>=0 && r<n && c<m);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        // int totalcost=0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m,false));
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        minheap.push({0,{0,0}});
        // visited[0][0] = true;
        while(!minheap.empty()){
            pip curr = minheap.top();
            int r= curr.second.first;
            int c = curr.second.second;
            int cost = curr.first;
            // int newcost = cost;
            minheap.pop();

            if(visited[r][c]){
                continue;
            }
            if(r==n-1 && c ==m-1){
                return cost;
            }
            visited[r][c] = true;

            for(int i=0;i<4;i++){
                int nrow= r+dir_x[i];
                int ncol = c+dir_y[i];
                if(isvalid(nrow,ncol,n,m)&& !visited[nrow][ncol]){
                    int newcost = cost;
                    newcost += (grid[r][c]==i+1)?0:1;
                    minheap.push({newcost,{nrow,ncol}});
                } 
            }
        }
        return -1;
    }
};
