class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    walkIsland(q, grid, i, j);
                    goto label;
                }
            }
        }

        label:
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            bool bridged = false;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                bridged |= expand(q, grid, p.first, p.second);
            }
            if (bridged)
                break;
            res++;
        }
        return res;
    }

    void walkIsland(queue<pair<int, int>> &q,vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        grid[i][j] = 2;
        q.push({i, j});
        // up
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            walkIsland(q, grid, i - 1, j);
        }
        // down
        if (i + 1 <= n - 1 && grid[i + 1][j] == 1) {
            walkIsland(q, grid, i + 1, j);
        }
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            walkIsland(q, grid, i, j - 1);
        }
        // right
        if (j + 1 <= n - 1 && grid[i][j + 1] == 1) {
            walkIsland(q, grid, i, j + 1);
        }
    }

    bool expand(queue<pair<int, int>> &q, vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        bool bridged = false;

        // up
        if (i - 1 >= 0) {
            if (grid[i - 1][j] == 0) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            } else if (grid[i - 1][j] == 1) {
                bridged |= true;
            }
        }
        // down
        if (i + 1 <= n - 1) {
            if (grid[i + 1][j] == 0) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            } else if (grid[i + 1][j] == 1) {
                bridged |= true;
            }
        }
        // left
        if (j - 1 >= 0) {
            if (grid[i][j - 1] == 0) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            } else if (grid[i][j - 1] == 1) {
                bridged |= true;
            }
        }
        // right
        if (j + 1 <= n - 1) {
            if (grid[i][j + 1] == 0) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            } else if (grid[i][j + 1] == 1) {
                bridged |= true;
            }
        }

        return bridged;
    }
};