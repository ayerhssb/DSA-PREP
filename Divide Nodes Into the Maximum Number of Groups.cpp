class Solution {
public:
    bool isComponentBipartite(vector<vector<int>>& adj, vector<int>& state,
                              int start) {
        queue<int> q;
        q.push(start);
        state[start] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]) {
                if (state[it] == 0) {
                    state[it] = state[curr] * (-1);
                    q.push(it);
                } else if (state[it] == state[curr]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj, int n) {
        vector<int> state(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0 && !isComponentBipartite(adj, state, i)) {
                return false;
            }
        }
        return true;
    }

    int countlevels(vector<vector<int>>& adj, int n, int source) {
        vector<int> vis(n + 1, 0);
        vis[source] = 1;
        queue<int> q;
        q.push(source);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (auto it : adj[curr]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            level++;
        }
        return level;
    }

    int maxlevelsBfs(vector<int>& maxdist,vector<vector<int>>& adj, vector<int>& visited, int source) {

        visited[source] = 1;
        queue<int> q;
        q.push(source);

        int maxlevel = -1;
        while (!q.empty()) {

            int curr = q.front();
            q.pop();
            maxlevel = max(maxlevel, maxdist[curr]);
            for (int it : adj[curr]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return maxlevel;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        if (!isBipartite(adj, n)) {
            return -1;
        }

        vector<int> maxdist(n + 1);
        for (int i = 1; i <= n; i++) {
            maxdist[i] = countlevels(adj,n, i);
        }

        int maxgroup = 0;
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                maxgroup += maxlevelsBfs(maxdist,adj, visited, i);
            }
        }

        return maxgroup;
    }
};
