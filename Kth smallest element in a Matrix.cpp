//better approach
//TC- O(n^2* log(k)) and SC- O(k)

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size(), m=mat[0].size();
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur=mat[i][j];
                pq.push(cur);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};


//TC- O(n^2* log(n^2)) and SC- O(n*m)
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size(), m=mat[0].size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};
