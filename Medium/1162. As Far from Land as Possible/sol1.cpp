class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        if (q.size() == n * n || q.size() == 0)
            return -1;

        int step = -1;
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int s = 0; s < size; s++) {
                pair<int, int> p = q.front();
                int i = p.first, j = p.second;
                q.pop();
                // up: i-1, j
                if (i-1 >= 0 && !grid[i-1][j]) {
                    q.push({i-1, j});
                    grid[i-1][j] = 1;
                }
                // down: i+1, j
                if (i+1 < n && !grid[i+1][j]) {
                    q.push({i+1, j});
                    grid[i+1][j] = 1;
                }
                // left: i, j-1
                if (j-1 >= 0 && !grid[i][j-1]) {
                    q.push({i, j-1});
                    grid[i][j-1] = 1;
                }
                // right: i, j+1
                if (j+1 < n && !grid[i][j+1]) {
                    q.push({i, j+1});
                    grid[i][j+1] = 1;
                }
            }
        }
        return step;
    }
};