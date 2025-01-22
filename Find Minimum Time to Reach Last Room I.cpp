class Solution {
    vector<int> dir = {-1,0,1,0,-1};
    bool isvalid(int& row, int& col, int& n, int& m) {
        return (row >= 0 && col >= 0 && row < n && col < m);
    }

    struct Node {
        int row, col, time;
        Node(int row, int col, int time) {
            this->row = row;
            this->col = col;
            this->time = time;
        }
    };

    struct comparator {
        bool operator()(Node* p1, Node* p2) { return p1->time > p2->time; }
    };

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        priority_queue<Node*, vector<Node*>, comparator> minheap;
        // int res = 0;
        Node* start = new Node(0, 0, 0);
        minheap.push(start);
        visited[0][0] = 1;
        while(!minheap.empty()){
            Node* curr = minheap.top();
            minheap.pop();

            int row = curr->row;
            int col = curr->col;
            int time = curr->time;

            if (row == n - 1 && col == m - 1) {
                return time;
            }

            // int dist_x[4] = {0, -1, 0, 1};
            // int dist_y[4] = {1, 0, -1, 0};

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i];
                int ncol = col + dir[i+1];
                if (isvalid(nrow, ncol, n, m) && !visited[nrow][ncol]) {
                    Node* newnode = new Node(
                        nrow, ncol,1+max(time,moveTime[nrow][ncol]));
                    minheap.push(newnode);
                    visited[nrow][ncol] = 1;
                }
            }

            
        }

        return -1;
    }
};
