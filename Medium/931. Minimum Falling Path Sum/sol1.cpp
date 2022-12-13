/* DP without memoization -> TLE */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mtx) {
        int ans = INT_MAX;
        for(int x = 0; x < mtx.size(); x++) {
            int tmp = traverse(x, 0, mtx);
            cout << mtx[0][x] << ", " << tmp << endl;
            if(ans > tmp)
                ans = tmp;
        }
        return ans;
    }

    int traverse(int x, int y, const vector<vector<int>>& mtx) {
        if(y == mtx.size() - 1) {
            // last layer
            if(x >= 0 || x <= mtx.size() - 1)
                return mtx[y][x];
            return INT_MAX;
        }
        int l = INT_MAX, m = INT_MAX, r = INT_MAX;
        if(x > 0) {
            l = traverse(x - 1, y + 1, mtx);
        }
        m = traverse(x, y + 1, mtx);
        if(x < mtx.size() - 1) {
            r = traverse(x + 1, y + 1, mtx);
        }
        return mtx[y][x] + min3(l, m, r);
    }

    int min3(const int& a, const int& b, const int& c) {
        if(a <= b && a <= c)
            return a;
        if(b <= a && b <= c)
            return b;
        if(c <= a && c <= b)
            return c;
        return INT_MAX;
    }
};