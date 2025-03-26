class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size(), m= grid[0].size();
        int rem=grid[0][0]%x;
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]%x!= rem){
                    return -1;
                }
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int mid = arr.size()>>1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum += (abs(arr[i]-arr[mid]))/x;
        }
        return sum;

    }
};
