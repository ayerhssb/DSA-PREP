// And also a smart pruning technique is to check the frequency of first and
// last char of the word in the board, and if the freq of first char is greater
// than last one, simple reverse the string and find the result

class Solution {
public:
    bool helper(int row, int col, vector<vector<char>>& board, string& word,
                int index, int m, int n, vector<vector<int>> vis) {
        if (index == word.size()) {
            return true;
        }
        if (row >= m || col >= n || row < 0 || col < 0 ||
            board[row][col] == '0' || board[row][col] != word[index]) {
            return false;
        }

        char c = board[row][col];
        board[row][col] = '0';

        bool res = helper(row + 1, col, board, word, index + 1, m, n, vis) ||
                   helper(row, col + 1, board, word, index + 1, m, n, vis) ||
                   helper(row, col - 1, board, word, index + 1, m, n, vis) ||
                   helper(row - 1, col, board, word, index + 1, m, n, vis);
        board[row][col] = c;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        // int index = 0;
        unordered_map<char,int> mpp;
        for(int i=0;i<word.size();i++){
            mpp[word[i]]++;
        }
        if(mpp[word[word.size()-1]]<=mpp[word[0]]){
            reverse(word.begin(),word.end());
        }
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if ( helper(i, j, board, word, 0, m, n, vis))
                        return true;
                }
            }
        }

        return false;
    }
};
