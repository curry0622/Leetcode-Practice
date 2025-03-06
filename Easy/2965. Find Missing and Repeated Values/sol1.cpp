class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int freq[2501] = {};
        int n = grid.size();
        for (const auto& row : grid) {
            for (const auto& n : row) {
                freq[n]++;
            }
        }
        vector<int> res(2, 0);
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2) res[0] = i;
            if (freq[i] == 0) res[1] = i;
        }
        return res;
    }
};