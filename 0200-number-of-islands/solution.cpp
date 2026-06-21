class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Edge case: empty grid
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        // Scan every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;      // Found new island
                    dfs(grid, i, j);     // Sink entire island
                }
            }
        }
        return islandCount;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: bounds check and water check
        if (i < 0 || i >= grid.size() || 
            j < 0 || j >= grid[0].size() || 
            grid[i][j] == '0') {
            return;
        }
        
        // Mark as visited by sinking
        grid[i][j] = '0';
        
        // Explore all 4 directions
        dfs(grid, i + 1, j);  // Down
        dfs(grid, i - 1, j);  // Up
        dfs(grid, i, j + 1);  // Right
        dfs(grid, i, j - 1);  // Left
    }
};
