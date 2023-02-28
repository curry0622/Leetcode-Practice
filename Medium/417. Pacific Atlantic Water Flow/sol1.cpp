class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Vatiables
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atalantic(m, vector<bool>(n, false));

        // Traversal
        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, n-1, heights, atalantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
            dfs(m-1, j, heights, atalantic);
        }

        // Result
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atalantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(int i, int j, const vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        int m = heights.size();
        int n = heights[0].size();
        int h = heights[i][j];
        ocean[i][j] = true;

        // up: i-1,j
        if (i-1 >= 0 && !ocean[i-1][j] && heights[i-1][j] >= h) {
            dfs(i-1, j, heights, ocean);
        }
        // down: i+1, j
        if (i+1 < m && !ocean[i+1][j] && heights[i+1][j] >= h) {
            dfs(i+1, j, heights, ocean);
        }
        // left: i,j-1
        if (j-1 >= 0 && !ocean[i][j-1] && heights[i][j-1] >= h) {
            dfs(i, j-1, heights, ocean);
        }
        // right: i,j+1
        if (j+1 < n && !ocean[i][j+1] && heights[i][j+1] >= h) {
            dfs(i, j+1, heights, ocean);
        }
    }
};