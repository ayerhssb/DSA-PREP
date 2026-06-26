#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int minTimeToDestination (vector<vector<int>>& signal) {
        int n=signal.size(), m=signal[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int dir_x[4] = {0,1,0,-1};
        int dir_y[4] = {1,0,-1,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto top= pq.top();
            int row  = top.second.first, col=top.second.second, t=top.first;
            pq.pop();
            if(dist[row][col]<t){continue;}
            // if(row==(n-1) && col==(m-1)){return t;}
            for(int i=0;i<4;i++){
                int newrow = row+dir_x[i], newcol = col+dir_y[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && t<dist[newrow][newcol]){
                    int arrival = max(t+1,signal[newrow][newcol]+1);
                        if(arrival< dist[newrow][newcol]){
                            pq.push({arrival, {newrow, newcol}});
                            dist[newrow][newcol]=arrival;
                        }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
