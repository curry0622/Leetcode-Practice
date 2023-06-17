class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dx = c[1][0] - c[0][0];
        int dy = c[1][1] - c[0][1];

        for (int i = 2; i < c.size(); i++) {
            int tx = c[i][0] - c[0][0];
            int ty = c[i][1] - c[0][1];
            if (dx * ty - dy * tx != 0)
                return false;
        }

        return true;
    }
};