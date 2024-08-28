class Solution {
public:
    vector<vector<int>> g1;
    vector<vector<int>> g2;
    int m, n;

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        g1 = grid1;
        g2 = grid2;
        m = g1.size(), n = g1[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g2[i][j]) {
                    bool isSubIsland = true;
                    traverse(i, j, isSubIsland);
                    if (isSubIsland) res++;
                }
            }
        }

        return res;
    }

    void traverse(int i, int j, bool& isSubIsland) {
        isSubIsland &= g1[i][j];
        // up
        if (i-1 >= 0 && g2[i-1][j]) {
            g2[i-1][j] = 0;
            traverse(i-1, j, isSubIsland);
        }
        // down
        if (i+1 < m && g2[i+1][j]) {
            g2[i+1][j] = 0;
            traverse(i+1, j, isSubIsland);
        }
        // left
        if (j-1 >= 0 && g2[i][j-1]) {
            g2[i][j-1] = 0;
            traverse(i, j-1, isSubIsland);
        }
        // right
        if (j+1 < n && g2[i][j+1]) {
            g2[i][j+1] = 0;
            traverse(i, j+1, isSubIsland);
        }
    }
};