class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, int> val2Idx;
            for (int i = 0; i < n; i++) {
                val2Idx[arr[i]] = i;
            }
            vector<vector<int>> dp(n, vector<int>(n, 2));
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (i == j) {
                        dp[i][j] = 1;
                    } else if (arr[j] - arr[i] < arr[i] &&
                               val2Idx.find(arr[j] - arr[i]) != val2Idx.end()) {
                        int k = val2Idx[arr[j] - arr[i]];
                        dp[i][j] = dp[k][i] + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
            return res == 2 ? 0 : res;
        }
};
