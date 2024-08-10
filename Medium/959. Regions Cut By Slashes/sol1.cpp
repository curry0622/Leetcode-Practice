class Solution {
public:
    int n;
    int regionsBySlashes(vector<string>& g) {
        n = g.size();
        int res = 0;
        vector<vector<bool>> v(n, vector<bool>(2 * n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2*n; j++) {
                if (!v[i][j]) {
                    traverse(g, v, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void traverse(const vector<string>& g, vector<vector<bool>>& v, int i, int j) {
        v[i][j] = true;
        /* Left */
        if (j % 2 == 0) {
            // cout << "j % 2 == 0" << endl;
            // top left
            // cout << "top left" << endl;
            if (i-1 >= 0 && j-1 >= 0 && !v[i-1][j-1]) {
                // don't care
            }
            // top
            // cout << "top" << endl;
            if (i-1 >= 0 && !v[i-1][j]) {
                if (!(g[i-1][j/2] == '/' || g[i][j/2] == '\\')) {
                    traverse(g, v, i-1, j);
                }
            }
            // top right
            // cout << "top right" << endl;
            if (i-1 >= 0 && j+1 < 2*n && !v[i-1][j+1]) {
                if (g[i-1][j/2] == g[i][j/2] && g[i-1][j/2] != '\\') {
                    traverse(g, v, i-1, j+1);
                }
            }
            // left
            // cout << "left" << endl;
            if (j-1 >= 0 && !v[i][j-1]) {
                traverse(g, v, i, j-1);
            }
            // right
            // cout << "right" << endl;
            if (j+1 < 2*n && !v[i][j+1]) {
                if (g[i][j/2] == ' ') {
                    traverse(g, v, i, j+1);
                }
            }
            // bot left
            // cout << "bot left" << endl;
            if (i+1 < n && j-1 >= 0 && !v[i+1][j-1]) {
                // don't care
            }
            // bot
            // cout << "bot" << endl;
            if (i+1 < n && !v[i+1][j]) {
                if (!(g[i][j/2] == '/' || g[i+1][j/2] == '\\')) {
                    traverse(g, v, i+1, j);
                }
            }
            // bot right
            // cout << "bot right" << endl;
            if (i+1 < n && j+1 < 2*n && !v[i+1][j+1]) {
                if (g[i][j/2] == g[i+1][j/2] && g[i][j/2] != '/') {
                    traverse(g, v, i+1, j+1);
                }
            }
        }
        /* Right */
        else {
            // cout << "j % 2 == 1" << endl;
            // top left
            // cout << "top left" << endl;
            if (i-1 >= 0 && j-1 >= 0 && !v[i-1][j-1]) {
                if (g[i-1][j/2] == g[i][j/2] && g[i][j/2] != '/') {
                    traverse(g, v, i-1, j-1);
                }
            }
            // top
            // cout << "top" << endl;
            if (i-1 >= 0 && !v[i-1][j]) {
                if (!(g[i-1][j/2] == '\\' || g[i][j/2] == '/')) {
                    traverse(g, v, i-1, j);
                }
            }
            // top right
            // cout << "top right" << endl;
            if (i-1 >= 0 && j+1 < 2*n && !v[i-1][j+1]) {
                // don't care
            }
            // left
            // cout << "left" << endl;
            if (j-1 >= 0 && !v[i][j-1]) {
                if (g[i][j/2] == ' ') {
                    traverse(g, v, i, j-1);
                }
            }
            // right
            // cout << "right" << endl;
            if (j+1 < 2*n && !v[i][j+1]) {
                traverse(g, v, i, j+1);
            }
            // bot left
            // cout << "bot left" << endl;
            if (i+1 < n && j-1 >= 0 && !v[i+1][j-1]) {
                if (g[i+1][j/2] == g[i][j/2] && g[i][j/2] != '\\') {
                    traverse(g, v, i+1, j-1);
                }
            }
            // bot
            // cout << "bot" << endl;
            if (i+1 < n && !v[i+1][j]) {
                if (!(g[i][j/2] == '\\' || g[i+1][j/2] == '/')) {
                    traverse(g, v, i+1, j);
                }
            }
            // bot right
            // cout << "bot right" << endl;
            if (i+1 < n && j+1 < 2*n && !v[i+1][j+1]) {
                // don't care
            }
        }
    }
};