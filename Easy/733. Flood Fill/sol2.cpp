class Solution {
public:
    vector<vector<int>> img;
    int m, n, orgClr, newClr;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        img = image;
        m = img.size();
        n = img[0].size();
        orgClr = img[sr][sc];
        newClr = color;

        if(orgClr != newClr)
            fill(sr, sc);

        return img;
    }

    void fill(int i, int j) {
        img[i][j] = newClr;

        // up
        if(i > 0 && img[i - 1][j] == orgClr) {
            fill(i - 1, j);
        }
        // down
        if(i < m - 1 && img[i + 1][j] == orgClr) {
            fill(i + 1, j);
        }
        // left
        if(j > 0 && img[i][j - 1] == orgClr) {
            fill(i, j - 1);
        }
        // right
        if(j < n - 1 && img[i][j + 1] == orgClr) {
            fill(i, j + 1);
        }
    }
};