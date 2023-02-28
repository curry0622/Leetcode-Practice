class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        while (q.size() > 0) {
            int size = q.size();
            bool pushed = false;

            for (int s = 0; s < size; s++) {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;

                // up: i-1,j
                if (i-1 >= 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    pushed = true;
                }
                // down: i+1,j
                if (i+1 < m && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    pushed = true;
                }
                // left: i,j-1
                if (j-1 >= 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    pushed = true;
                }
                // right: i,j+1
                if (j+1 < n && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    pushed = true;
                }
            }

            if (pushed)
                time++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};

// 2 2
// 1 1
// 0 0
// 2 0