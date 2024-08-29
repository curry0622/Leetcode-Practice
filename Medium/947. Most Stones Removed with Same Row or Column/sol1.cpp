class Solution {
public:
    int m, n;

    int removeStones(vector<vector<int>>& stones) {
        sort(stones.begin(), stones.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int lastVal = stones[0][0], lastIndex = 0;
        stones[0][0] = 0;
        for (int i = 1; i < stones.size(); i++) {
            if (stones[i][0] == lastVal) {
                stones[i][0] = lastIndex;
            } else {
                lastVal = stones[i][0];
                lastIndex++;
                stones[i][0] = lastIndex;
            }
        }
        m = lastIndex + 1;

        sort(stones.begin(), stones.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        lastVal = stones[0][1], lastIndex = 0;
        stones[0][1] = 0;
        for (int i = 1; i < stones.size(); i++) {
            if (stones[i][1] == lastVal) {
                stones[i][1] = lastIndex;
            } else {
                lastVal = stones[i][1];
                lastIndex++;
                stones[i][1] = lastIndex;
            }
        }
        n = lastIndex + 1;

        vector<vector<bool>> g(m, vector<bool>(n, false));
        for (auto s : stones) {
            g[s[0]][s[1]] = true;
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    traverse(g, i, j);
                    cnt++;
                }
            }
        }

        return stones.size() - cnt;
    }

    void traverse(vector<vector<bool>>& g, int x, int y) {
        g[x][y] = false;
        for (int i = 0; i < m; i++) {
            if (g[i][y]) traverse(g, i, y);
        }
        for (int i = 0; i < n; i++) {
            if (g[x][i]) traverse(g, x, i);
        }
    }
};