#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
*/

class solution {
   public:
    int locateMinimumLevel(Node* treeRoot) {
        if (!treeRoot) {
            return 0;
        }
        queue<Node*> q;
        q.push(treeRoot);
        long long minsum = INT_MAX; int level = 0, ans = 1;
        while (!q.empty()) {
            int n = q.size();
            int k = n;
            long long sum = 0;
            level++;
            while (k--) {
                Node* temp = q.front();
                q.pop();
                sum += (temp->data);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            if (sum < minsum) {
                minsum = min<long long>(sum, minsum);
                ans = level;
            }
        }
        return ans;
    }
};
