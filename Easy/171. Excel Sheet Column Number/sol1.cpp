class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = columnTitle.size() - 1, exp = 0; i >= 0; i--, exp++) {
            ans += (columnTitle[i] - 64) * pow(26, exp);
        }
        return ans;
    }
};