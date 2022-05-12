class Solution {
public:
    void dir(vector<vector<int>>& grid, int i, int j, int& num) {
        num++;
        grid[i][j] = 0;
        // up
        if(i > 0 && grid[i - 1][j] == 1) {
            dir(grid, i - 1, j, num);
        }
        // down
        if(i < grid.size() - 1 && grid[i + 1][j] == 1) {
            dir(grid, i + 1, j, num);
        }
        // left
        if(j > 0 && grid[i][j - 1] == 1) {
            dir(grid, i, j - 1, num);
        }
        // right
        if(j < grid[i].size() - 1 && grid[i][j + 1] == 1) {
            dir(grid, i, j + 1, num);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    int tmp = 0;
                    dir(grid, i, j, tmp);
                    if(max < tmp)
                        max = tmp;
                }
            }
        }
        return max;
    }
};