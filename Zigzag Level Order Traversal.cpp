class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if (root == NULL)
            return ans;
        qu.push(root);
        bool flag = true;
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();

                int index = flag ? i : (size - i - 1);
                row[index] = node->val;

                if (node->left) {
                    qu.push(node->left);
                }
                if (node->right) {
                    qu.push(node->right);
                }
            }

            flag = !flag;
            ans.push_back(row);
        }

        return ans;
    }
};