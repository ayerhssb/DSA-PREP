class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int len = m*n;
        vector<int> row(m,0), col(n,0);
        map<int,pair<int,int>> lookup;
        // vector<pair<int,int>> lookup(len);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                lookup[mat[i][j]].first = i;
                lookup[mat[i][j]].second = j;
            }
        }

        for(int i=0;i<len;i++){
            int r = lookup[arr[i]].first;
            int c = lookup[arr[i]].second;
            row[r]++;
            col[c]++;
            if(row[r] == n){
                return i;
            }
            if(col[c]==m){
                return i;
            }
        }
        return -1;
    }
};
