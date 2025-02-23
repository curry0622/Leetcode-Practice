class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> sums;
        for (int i = 0; i < grid.size(); i++) {
            int l = limits[i];
            nth_element(grid[i].begin(), grid[i].begin() + l,
                        grid[i].end(), greater<int>());
            for (int j = 0; j < l; j++) {
                sums.push_back(grid[i][j]);
            }
        }
        nth_element(sums.begin(), sums.begin() + k,
                    sums.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < k; i++) {
            res += sums[i];
        }
        return res;
    }
};