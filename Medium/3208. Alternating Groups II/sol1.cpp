class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> concatColors = colors;
        concatColors.insert(concatColors.end(), colors.begin(), colors.end());
        int n = concatColors.size();
        int l = 0, r = 0;
        int last = concatColors[0];
        int res = 0;
        int start = INT_MIN;
        for (int i = 1; i < n && l < n && r < n; i++) {
            if (l == start || l == start + n / 2) {
                break;
            }
            int len = r - l + 1;
            if (len == k) {
                res++;
                if (res == 1) {
                    start = l;
                }
                if (concatColors[i] == concatColors[r]) {
                    l = i;
                    r = i;
                } else {
                    l++;
                    r++;
                }
            } else if (len < k) {
                if (concatColors[i] == concatColors[r]) {
                    l = i;
                    r = i;
                } else {
                    r++;
                }
            }
        }
        return res;
    }
};