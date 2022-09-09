class Solution {
public:
    vector<vector<int>> img;
    int m, n, clr;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        img = image;
        m = img.size();
        n = img[0].size();
        clr = color;

        fill(sr, sc);
        adjust();

        return img;
    }

    void fill(int i, int j) {
        int org = img[i][j];
        img[i][j] = INT_MAX;

        // up
        if(i > 0 && img[i - 1][j] == org) {
            fill(i - 1, j);
        }
        // down
        if(i < m - 1 && img[i + 1][j] == org) {
            fill(i + 1, j);
        }
        // left
        if(j > 0 && img[i][j - 1] == org) {
            fill(i, j - 1);
        }
        // right
        if(j < n - 1 && img[i][j + 1] == org) {
            fill(i, j + 1);
        }
    }

    void adjust() {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(img[i][j] == INT_MAX)
                    img[i][j] = clr;
            }
        }
    }
};