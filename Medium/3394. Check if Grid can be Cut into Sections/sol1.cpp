class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sortX(rectangles);
        int pbx = 0, pux = 0;
        int lineCnt = -1;
        for (auto r : rectangles) {
            int bx = r[0], ux = r[2];
            if (pux <= bx) {
                lineCnt++;
                pbx = bx;
                pux = ux;
            } else {
                pux = max(pux, ux);
            }
        }
        if (lineCnt >= 2) {
            return true;
        }
        sortY(rectangles);
        int pby = 0, puy = 0;
        lineCnt = -1;
        for (auto r : rectangles) {
            int by = r[1], uy = r[3];
            if (puy <= by) {
                lineCnt++;
                pby = by;
                puy = uy;
            } else {
                puy = max(puy, uy);
            }
        }
        return lineCnt >= 2;
    }

    void sortX(vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
    }

    void sortY(vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
    }
};