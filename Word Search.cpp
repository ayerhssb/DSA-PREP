//rev:
class Solution {
  public:
    bool helper(vector<vector<char>> &mat, string &word, int x, int y, int wIndex){
        int wlen=word.size();int n=mat.size(), m=mat[0].size();
        if(wIndex==wlen){return true;}
        if(x<0||y<0||x>=n||y>=m){return false;}
        if(word[wIndex]==mat[x][y]){
            char temp = mat[x][y];
            mat[x][y] = '!';
            
            bool res= helper(mat,word,x+1,y,wIndex+1)||helper(mat,word,x-1,y,wIndex+1)
            ||helper(mat,word,x,y+1,wIndex+1)||helper(mat,word,x,y-1,wIndex+1);
            
            mat[x][y]=temp;
            return res;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int wlen=word.size();
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    if(helper(mat,word,i,j,0)){return true;}
                }
            }
        }
        return false;
    }
};



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
