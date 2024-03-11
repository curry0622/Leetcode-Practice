class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c-'a']++;
        }
        for (char c : order) {
            int n = cnt[c-'a'];
            res += string(n, c);
            cnt[c-'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            res += string(cnt[i], char('a'+i));
        }
        return res;
    }
};