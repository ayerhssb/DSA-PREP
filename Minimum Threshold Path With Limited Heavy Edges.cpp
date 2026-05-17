class Solution {
public:
    bool isValid(int n, int t, vector<vector<pair<int, int>>>& adj, int source,
                 int target, int k) {
        vector<int> dist(n, 1e9);
        dist[source] = 0;
        deque<int> q;
        q.push_front(source);
        while (!q.empty()) {
            int node = q.front();
            q.pop_front();
            for (auto it : adj[node]) {
                int node1 = it.first, wt1 = it.second;
                int cost = (wt1 > t) ? 1 : 0;
                if (dist[node] + cost < dist[node1]) {
                    dist[node1] = dist[node] + cost;
                    if (cost == 1) {
                        q.push_back(node1);
                    } else {
                        q.push_front(node1);
                    }
                }
            }
        }
        return dist[target] <= k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {
        int t = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
            t = max(t, it[2]);
        }

        int l = 0, h = t, ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (isValid(n, mid, adj, source, target, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
