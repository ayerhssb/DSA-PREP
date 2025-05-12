// User function template for C++

class Solution {
  public:
    void helper(int row, int col, int n, vector<vector<int>>& maze, vector<string>& ans, string list, vector<vector<int>> vis){
        if( row == n-1 && col == n-1){
            ans.push_back(list);
            return;
        }
        if(row<0||col<0||col>=n||row>=n||vis[row][col]||maze[row][col]==0){
            return;
        }
        vis[row][col]=1;
        helper(row+1,col,n,maze,ans, list+'D',vis);
        helper(row,col-1,n,maze,ans, list+'L',vis);
        helper(row,col+1,n,maze,ans, list+'R',vis);
        helper(row-1,col,n,maze,ans, list+'U',vis);
        list.pop_back();
        vis[row][col]=0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        if(maze[0][0]==0) return ans;
        int n=maze.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        string list;
        helper(0,0,n,maze,ans,list,vis);
        return ans;
    }
};
