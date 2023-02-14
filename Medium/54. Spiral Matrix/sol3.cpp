class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        int m = mtx.size(), n = mtx[0].size(), size = m*n;
        int ub = 0, rb = n-1, db = m-1, lb = 0;
        vector<int> res(size);

        int s = 0;
        while (s < size) {
            // right
            for (int i = lb; i <= rb && s < size; i++) {
                res[s] = mtx[ub][i];
                s++;
            }
            ub++;
            // down
            for (int i = ub; i <= db && s < size; i++) {
                res[s] = mtx[i][rb];
                s++;
            }
            rb--;
            // left
            for (int i = rb; i >= lb && s < size; i--) {
                res[s] = mtx[db][i];
                s++;
            }
            db--;
            // up
            for (int i = db; i >= ub && s < size; i--) {
                res[s] = mtx[i][lb];
                s++;
            }
            lb++;
        }

        return res;
    }
};