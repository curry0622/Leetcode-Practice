class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    walk(i, j, grid);
                    num++;
                }
            }
        }
        return num;
    }

    void walk(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        // up: i-1, j
        if (i-1 >= 0 && grid[i-1][j] == '1')
            walk(i-1, j, grid);
        // down: i+1, j
        if (i+1 < grid.size() && grid[i+1][j] == '1')
            walk(i+1, j, grid);
        // left: i, j-1
        if (j-1 >= 0 && grid[i][j-1] == '1')
            walk(i, j-1, grid);
        // right: i, j+1
        if (j+1 < grid[0].size() && grid[i][j+1] == '1')
            walk(i, j+1, grid);
    }
};