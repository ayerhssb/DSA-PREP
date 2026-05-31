class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mpp;
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {

            mpp[arr[i]].push_back(i);
        }
        q.push(0);
        vis[0] = 1;
        // if(mpp.find(arr[0])!=mpp.end()){
        //     auto it = mpp[arr[0]];
        //     for(int i:it){
        //         q.push(i);
        //         vis[i]=1;
        //     }
        // }
        int minstep = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int idx = q.front();
                int node = arr[idx];
                q.pop();
                // int step = 0;
                if (idx == n - 1) {
                    return minstep;
                }

                if (mpp.find(node) != mpp.end()) {
                    auto it = mpp[node];
                    for (int k : it) {
                        q.push(k);
                        vis[k] = 1;
                    }
                    mpp.erase(node);
                }

                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }
            }
            minstep++;
        }

        return minstep;
    }
};
