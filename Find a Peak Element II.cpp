class Solution {
public:
    int maxEl(int mid, int n,vector<vector<int>>& mat ){
        int maxi=INT_MIN,row=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){maxi=mat[i][mid]; row=i;} 
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int row=maxEl(mid,n, mat);
            int left = ((mid-1)>=0)? mat[row][mid-1]: -1;
            int right = ((mid+1)<m)? mat[row][mid+1]: -1;
            if((mat[row][mid]>left) && (mat[row][mid]>right)) {return {row, mid};}
            else if(left>mat[row][mid]) {high=mid-1;}
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};
