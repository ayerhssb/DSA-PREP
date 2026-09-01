#include <bits/stdc++.h>
using namespace std;

class solution {
  public:
  int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  int minCostToValidPath(vector<vector<int>>& grid) { 
      int n=grid.size(), m=grid[0].size();
      vector<vector<int>> cost(n, vector<int>(m,INT_MAX));
      priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
      cost[0][0]=0;
      pq.push({0,0,0});
      while(!pq.empty()){
          auto curr=pq.top(); pq.pop();
          int currcost=curr[0];
          int r=curr[1], c=curr[2];
          if(cost[r][c]<currcost){continue;}
          for(int i=0;i<4;i++){
              int nr=r+dir[i][0], nc=c+dir[i][1];
              if(nr>=0&&nc>=0&&nr<n&&nc<m){
                  int gridDir = grid[r][c];
                  int cost_ = (gridDir-1==i)?0:1;
                  if(currcost+cost_ < cost[nr][nc]){
                      cost[nr][nc] = currcost+cost_;
                      pq.push({cost[nr][nc], nr,nc});
                  }
              }
          }
      }
      return cost[n-1][m-1];
  }
};
