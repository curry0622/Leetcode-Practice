class Solution {
public:
    int possibleStringCount(string word) {
        int len = word.size();
        char last = word[0];
        char curr;
        int ans = 1, cnt = 0;
        for (int i = 1; i < len; i++) {
            curr = word[i];
            if (last == curr) {
                cnt++;
            } else {
                ans += cnt;
                cnt = 0;
            }
            last = curr;
        }
        return ans + cnt;
    }
};