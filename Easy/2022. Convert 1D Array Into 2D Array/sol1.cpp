class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if (o.size() != m * n)
            return {};
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            vector<int> row(n, 0);
            for (int j = 0; j < n; j++) {
                row[j] = o[i * n + j];
            }
            res.push_back(row);
        }
        return res;
    }
};