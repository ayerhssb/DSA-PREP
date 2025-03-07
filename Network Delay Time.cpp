class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // int m = times.size();
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // priority_queue<pair<int,int>> pq;
        for(auto it:times){
            adj[it[0]].push_back({it[2],it[1]});
        }
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int currnode = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            for(auto& it:adj[currnode]){
                if(cost+it.first < dist[it.second]){
                    dist[it.second]= cost+it.first;
                    pq.push({dist[it.second],it.second});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }

        return ans;

    }
};
