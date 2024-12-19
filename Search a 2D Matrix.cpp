class Solution {
public:
    bool bs(vector<int>& arr, int target) {
        // if(arr.size()==1){if(arr[0]==target) return true;}
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (arr[mid] == target)
                return true;
            if (arr[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        // for(int i=0;i<n;i++){
        //     if(matrix[i][0]<=target && matrix[i][m-1]>=target){
        //         if(bs(matrix[i],target)) {return true;}
        //     }
        // }
        int ind1 = 0, ind2 = m - 1;
        while (ind1 < n && ind2 >= 0) {
            if(target==matrix[ind1][ind2]) return true;
            else if (target > matrix[ind1][ind2]) {
                ind1++;
            }
            else{
                ind2--;
            }
        }
        return false;
    }
};
