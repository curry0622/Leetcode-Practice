class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mtx) {
        int ans = INT_MAX;
        int n = mtx.size();
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                int l_idx = max(0, col - 1);
                int m_idx = col;
                int r_idx = min(n - 1, col + 1);
                int tmp = min(mtx[row - 1][l_idx], mtx[row - 1][m_idx]);
                mtx[row][col] += min(tmp, mtx[row - 1][r_idx]);
            }
        }
        for(auto& el : mtx.back()) {
            if(ans > el)
                ans = el;
        }
        return ans;
    }
};