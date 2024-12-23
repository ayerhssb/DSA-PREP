class Solution {
  public:
    bool bs(vector<int> mat, int x){
        int low=0,high=mat.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(mat[mid]==x)return true;
            else if(mat[mid]>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]<=x && mat[i][m-1]>=x){
                if(bs(mat[i],x)==true){return true;}
            }
            else{
                continue;
            }
        }
        return false;
    }
};
