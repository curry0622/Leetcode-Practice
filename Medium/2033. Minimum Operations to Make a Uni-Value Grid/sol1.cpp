class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        int re = grid[0][0] % x;
        for (auto row : grid) {
            for (auto el : row) {
                if (el % x != re) return -1;
                vec.push_back(el);
            }
        }
        sort(vec.begin(), vec.end());
        int target = vec[vec.size() / 2];
        int res = 0;
        for (auto el : vec) {
            res += abs(el - target) / x;
        }
        return res;
    }
};