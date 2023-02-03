class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52] = {0};
        for (const char&c : s) {
            if (c >= 'a')
                cnt[26 + c - 'a']++;
            else
                cnt[c - 'A']++;
        }
        int ans = 0;
        int has_odd = 0;
        for (int i = 0; i < 52; i++) {
            if (cnt[i] % 2 == 0)
                ans += cnt[i];
            else {
                has_odd = 1;
                ans += cnt[i] - 1;
            }
        }
        return ans + has_odd;
    }
};