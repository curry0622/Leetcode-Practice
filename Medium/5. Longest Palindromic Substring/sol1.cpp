class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), res = 0;
        pair<int, int> p;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; i+j < n; j++) {
                if (j+i == j)
                    dp[j][j+i] = 1;
                else if (s[j] == s[j+i] && i == 1)
                    dp[j][j+i] = 2;
                else if (s[j] == s[j+i] && dp[j+1][j+i-1] != 0)
                    dp[j][j+i] = dp[j+1][j+i-1] + 2;
                if (res < dp[j][j+i]) {
                    res = dp[j][j+i];
                    p = {j, j+i};
                }
            }
        }

        return s.substr(p.first, p.second-p.first+1);
    }
};