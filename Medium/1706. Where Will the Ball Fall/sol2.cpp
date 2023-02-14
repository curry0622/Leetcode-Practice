class Solution {
public:
    int m, n;

    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);

        if (n > 1)
            for (int j = 0; j < n; j++)
                res[j] = drop(0, j, grid);

        return res;
    }

    int drop(int i, int j, const vector<vector<int>>& grid) {
        // If not last row, keep dropping
        if (i < m-1) {
            if (grid[i][j] == 1 && j+1 < n && grid[i][j+1] == 1)
                return drop(i+1, j+1, grid);
            if (grid[i][j] == -1 && j-1 >= 0 && grid[i][j-1] == -1)
                return drop(i+1, j-1, grid);
            return -1;
        }

        // last row mid
        if (j > 0 && j < n-1) {
            if (grid[i][j] == 1 && grid[i][j+1] == 1)
                return j+1;
            if (grid[i][j] == -1 && grid[i][j-1] == -1)
                return j-1;
        }

        // last row edge
        if (j == 0 && grid[i][j] == 1 && grid[i][j+1] == 1)
            return j+1;
        if (j == n-1 && grid[i][j] == -1 && grid[i][j-1] == -1)
            return j-1;

        // else
        return -1;
    }
};