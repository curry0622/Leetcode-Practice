class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector<bool> a(26, false);
        for (char c : allowed) {
            a[c-'a'] = true;
        }
        for (string w : words) {
            int valid = 1;
            for (char c : w) {
                if (!a[c-'a'])
                    valid = 0;
            }
            res += valid;
        }
        return res;
    }
};