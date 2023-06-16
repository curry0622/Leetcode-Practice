class Solution {
public:
    int n;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] || grid[n-1][n-1])
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int len = 0;
        bool reached = false;
        while (!q.empty() && !reached) {
            int size = q.size();
            len++;
            for (int s = 0; s < size; s++) {
                pair<int, int> p = q.front();
                q.pop();

                if (p.first == n-1 && p.second == n-1) {
                    reached = true;
                    break;
                }

                bfs(grid, p.first, p.second, q);
            }
        }

        if (reached)
            return len;
        return -1;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        // top-right
        if (i - 1 >= 0 && j + 1 <= n - 1) {
            if (grid[i - 1][j + 1] == 0) {
                q.push({i - 1, j + 1});
                grid[i - 1][j + 1] = -1;
            }
        }
        // right
        if (j + 1 <= n - 1) {
            if (grid[i][j + 1] == 0) {
                q.push({i, j + 1});
                grid[i][j + 1] = -1;
            }
        }
        // bottom-right
        if (i + 1 <= n - 1 && j + 1 <= n - 1) {
            if (grid[i + 1][j + 1] == 0) {
                q.push({i + 1, j + 1});
                grid[i + 1][j + 1] = -1;
            }
        }
        // bottom
        if (i + 1 <= n - 1) {
            if (grid[i + 1][j] == 0) {
                q.push({i + 1, j});
                grid[i + 1][j] = -1;
            }
        }
        // bottom-left
        if (i + 1 <= n - 1 && j - 1 >= 0) {
            if (grid[i + 1][j - 1] == 0) {
                q.push({i + 1, j - 1});
                grid[i + 1][j - 1] = -1;
            }
        }
        // left
        if (j - 1 >= 0) {
            if (grid[i][j - 1] == 0) {
                q.push({i, j - 1});
                grid[i][j - 1] = -1;
            }
        }
        // top-left
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (grid[i - 1][j - 1] == 0) {
                q.push({i - 1, j - 1});
                grid[i - 1][j - 1] = -1;
            }
        }
        // top
        if (i - 1 >= 0) {
            if (grid[i - 1][j] == 0) {
                q.push({i - 1, j});
                grid[i - 1][j] = -1;
            }
        }
    }
};