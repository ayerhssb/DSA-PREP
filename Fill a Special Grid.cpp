class Solution {

private:
    void fillGrid(vector<vector<int>>& grid, int row, int col, int size, int startNum) {
        if (size == 1) {
            grid[row][col] = startNum;
            return;
        }
        
        int halfSize = size / 2;
        int elementsInQuadrant = halfSize * halfSize;
        
        // Fill top-right quadrant (smallest numbers)
        fillGrid(grid, row, col + halfSize, halfSize, startNum);
        
        // Fill bottom-right quadrant (second smallest)
        fillGrid(grid, row + halfSize, col + halfSize, halfSize, startNum + elementsInQuadrant);
        
        // Fill bottom-left quadrant (second largest)
        fillGrid(grid, row + halfSize, col, halfSize, startNum + 2 * elementsInQuadrant);
        
        // Fill top-left quadrant (largest numbers)
        fillGrid(grid, row, col, halfSize, startNum + 3 * elementsInQuadrant);
    }
    
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;  // Calculate 2^N
        vector<vector<int>> grid(size, vector<int>(size, 0));
        
        fillGrid(grid, 0, 0, size, 0);
        
        return grid;
    }
};©leetcode
