class Solution {
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {        
        if(heightMap.empty() || heightMap[0].empty()){
            return 0;
        }
        int n=heightMap.size(), m=heightMap[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<>> minheap;

        for(int j=0;j<m;j++){
            minheap.push({heightMap[0][j],{0,j}});
            minheap.push({heightMap[n-1][j],{n-1,j}});
            visited[0][j] = 1;
            visited[n-1][j]=1;
        }
        for(int i=1;i<n-1;i++){
            minheap.push({heightMap[i][0],{i,0}});
            minheap.push({heightMap[i][m-1],{i,m-1}});
            visited[i][0] = 1;
            visited[i][m-1]=1;
        }

        int totalwater=0;
        int dx[4] = {0,-1,1,0};
        int dy[4] = {-1,0,0,1};

        while(!minheap.empty()){
            int height = minheap.top().first;
            int x= minheap.top().second.first;
            int y= minheap.top().second.second;

            minheap.pop();

            for(int i=0;i<4;i++){
                int nrow= x+dx[i];
                int ncol = y+dy[i];
                if(nrow<0 || ncol>=m || nrow>=n || ncol<0 || visited[nrow][ncol]){
                    continue;
                }
                if(heightMap[nrow][ncol]<height){
                    totalwater += (height - heightMap[nrow][ncol]);
                    minheap.push({height,{nrow,ncol}});
                    
                }
                else{
                    minheap.push({heightMap[nrow][ncol],{nrow,ncol}});
                }
                visited[nrow][ncol]= 1;
            }

        }
        return totalwater;
        
    }
};
