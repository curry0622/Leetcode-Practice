class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // rows
        int mid = (n - 1) / 2;
        int rFlips = 0;
        for (auto row : grid) {
            for (int i = 0; i < mid; i++) {
                if (row[i] != row[n-1-i])
                    rFlips++;
            }
            if (n % 2 == 0 && row[mid] != row[mid+1])
                rFlips++;
        }

        // columns
        mid = (m - 1) / 2;
        int cFlips = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                if (grid[j][i] != grid[m-1-j][i])
                    cFlips++;
            }
            if (m % 2 == 0 && grid[mid][i] != grid[mid+1][i])
                cFlips++;
        }
        return min(rFlips, cFlips);
    }
};