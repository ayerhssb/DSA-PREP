class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
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
