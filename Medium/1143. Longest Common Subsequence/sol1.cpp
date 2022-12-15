class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = getVal(i-1, j-1, dp) + 1;
                } else {
                    dp[i][j] = max(getVal(i-1, j, dp), getVal(i, j-1, dp));
                }
            }
        }

        return dp[m-1][n-1];
    }

    int getVal(int i, int j, const vector<vector<int>>& dp) {
        if(i >= 0 && i < dp.size() && j >= 0 && j < dp[0].size()) {
            return dp[i][j];
        }
        return 0;
    }
};

// len(text1) = m
// len(text2) = n

// construct m * n array

// text1 = abcde, len = 5
// text2 = ace, len = 3

//  a c e
// a
// b
// c
// d
// e

// if text1[i] == text2[j], then arr[i][j] = arr[i-1][j-1] + 1
// else arr[i][j] = max(arr[i-1][j], arr[i][j-1])