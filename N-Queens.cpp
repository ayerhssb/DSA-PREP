#include <bits/stdc++.h>
using namespace std;

class solution {
  public:
//   bool issafe(int row, int col, int n, vector<int>& row, vector<int>& leftdiag,vector<int>& rightdiag, vector<vector<char>>& board){
      
//   }
  void solve(int idx, int n, vector<int>& row, vector<int>& leftdiag,vector<int>& rightdiag, vector<vector<char>>& board, vector<vector<string>>& ans){
      if(idx==n){
          vector<string> temp;
          for(int i=0;i<n;i++){
              string str=""; 
              for(int j=0;j<n;j++){
                  str+=board[i][j];
              }
              temp.push_back(str);
          }
          ans.push_back(temp);return;
      }
      for(int i=0;i<n;i++){
            int j=idx;
            if(row[i]==0 && leftdiag[i+j]==0 && rightdiag[n-1+i-j]==0){
                board[i][j]='Q';
                row[i]=1;
                leftdiag[i+j]=1;
                rightdiag[n-1+i-j]=1;
                solve(j+1, n, row, leftdiag, rightdiag, board, ans);
                board[i][j]='.';
                row[i]=0;
                leftdiag[i+j]=0;
                rightdiag[n-1+i-j]=0;
        }
    }
  }
  vector<vector<string>> nQueens(int n) { 
    vector<vector<char>>  board(n,vector<char>(n,'.'));
    vector<int> row(n+1,0);
    vector<int> leftdiag(2*n+1,0);
    vector<int> rightdiag(2*n+1,0); vector<vector<string>> ans;
    solve(0, n,row,leftdiag, rightdiag, board,ans);
    
    return ans;
  }
};
