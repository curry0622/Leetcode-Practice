class Solution {
public:
    int getWall(vector<vector<int>>& grid, int i, int j) {
        int wall = 0;
        if(grid[i][j] == 1) {
            if(i == 0)
                wall++;
            if(i == grid.size() - 1)
                wall++;
            if(j == 0)
                wall++;
            if(j == grid[i].size() - 1)
                wall++;
            // up
            if(i > 0 && grid[i - 1][j] == 0)
                wall++;
            // down
            if(i < grid.size() - 1 && grid[i + 1][j] == 0)
                wall++;
            // left
            if(j > 0 && grid[i][j - 1] == 0)
                wall++;
            // right
            if(j < grid[i].size() - 1 && grid[i][j + 1] == 0)
                wall++;
        }
        return wall;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                ans += getWall(grid, i, j);
            }
        }
        return ans;
    }
};