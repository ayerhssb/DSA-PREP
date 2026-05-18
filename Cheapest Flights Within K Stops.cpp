//revision:

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, int>>
            pq;
        pq.push({src, 0});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        int stop = 0;
        while (!pq.empty() && stop <= k) {
            int siz = pq.size();
            while (siz--) {
                int node = pq.front().first;
                int cost = pq.front().second;
                pq.pop();
                for (auto it : adj[node]) {
                    if (it.second + cost < dist[it.first]) {
                        dist[it.first] = it.second + cost;
                        pq.push({it.first, dist[it.first]});
                    }
                    
                }  
            }
            stop++;
        }
        if(dist[dst]==1e9){return -1;}

        return dist[dst];
    }
};





class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        prices[src]=0;
        while(!pq.empty()){
            auto curr = pq.front();
            int stops = curr.first;
            int currnode = curr.second.first;
            int price = curr.second.second;
            pq.pop();
            if(stops>k){
                break;
            }

            for(auto it:adj[currnode]){
                if(price+it.second < prices[it.first]){
                    prices[it.first] = price + it.second;
                    pq.push({stops+1, {it.first, prices[it.first]}});
                }
            }
        }

        for(int i=0;i<prices.size();i++){
            if(prices[i]==1e9){
                prices[i]=-1;
            }
        }

        return prices[dst];
    }
};
