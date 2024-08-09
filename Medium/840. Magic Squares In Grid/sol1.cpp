class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m < 3 || n < 3) return 0;

        int res = 0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (isValid(grid, i, j)) res++;
            }
        }
        return res;
    }

    bool isValid(vector<vector<int>>& g, int r, int c) {
        vector<bool> exist(10, false);
        for (int i = r-1; i <= r+1; i++) {
            for (int j = c-1; j <= c+1; j++) {
                if (g[i][j] < 1 || g[i][j] > 9) return false;
                if (exist[g[i][j]]) return false;
                exist[g[i][j]] = true;
            }
        }
        int sum = g[r-1][c-1] + g[r-1][c] + g[r-1][c+1];
        if (sum != g[r][c-1] + g[r][c] + g[r][c+1]) return false;
        if (sum != g[r+1][c-1] + g[r+1][c] + g[r+1][c+1]) return false;

        if (sum != g[r-1][c-1] + g[r][c-1] + g[r+1][c-1]) return false;
        if (sum != g[r-1][c] + g[r][c] + g[r+1][c]) return false;
        if (sum != g[r-1][c+1] + g[r][c+1] + g[r+1][c+1]) return false;

        if (sum != g[r-1][c-1] + g[r][c] + g[r+1][c+1]) return false;
        if (sum != g[r+1][c-1] + g[r][c] + g[r-1][c+1]) return false;

        return true;
    }
};