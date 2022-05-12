class Solution {
public:
    void dir(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        // up
        if(i > 0 && grid[i - 1][j] == '1') {
            dir(grid, i - 1, j);
        }
        // down
        if(i < grid.size() - 1 && grid[i + 1][j] == '1') {
            dir(grid, i + 1, j);
        }
        // left
        if(j > 0 && grid[i][j - 1] == '1') {
            dir(grid, i, j - 1);
        }
        // right
        if(j < grid[i].size() - 1 && grid[i][j + 1] == '1') {
            dir(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    dir(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};