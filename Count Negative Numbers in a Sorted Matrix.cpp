class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int i=grid.size()-1,j=0;
        while(i>=0&&j<grid[0].size()){
            if(grid[i][j]<0){
                ans+= (grid[0].size()-j);
                i--;
            }
            else{
                j++;
            }
        }
        return ans;
        //brute-noob approach
        // int ans=0;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]<0){ans++;}
        //     }
        // }
        // return ans;
    }
};
