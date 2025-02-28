class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            if (str1.empty()) return str2;
            if (str2.empty()) return str1;
            int len1 = str1.size(), len2 = str2.size();
            vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (str1[i-1] == str2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            int i = len1, j = len2;
            string res = "";
            while (i > 0 && j > 0) {
                if (str1[i-1] == str2[j-1]) {
                    res = str1[i-1] + res;
                    i--, j--;
                } else if (dp[i][j-1] > dp[i-1][j]) {
                    res = str2[j-1] + res;
                    j--;
                } else {
                    res = str1[i-1] + res;
                    i--;
                }
            }
            while (i > 0) {
                res = str1[i-1] + res;
                i--;
            }
            while (j > 0) {
                res = str2[j-1] + res;
                j--;
            }
            return res;
        }
    };

    //   x a b a c
    // x 0 0 0 0 0
    // c 0 0 0 0 1
    // a 0 1 1 1 1
    // b 0 1 2 2 2