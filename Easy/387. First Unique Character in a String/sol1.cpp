class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> record(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (record[s[i]-'a'] == -1) {
                record[s[i]-'a'] = i;
            } else if (record[s[i]-'a'] != -2) {
                record[s[i]-'a'] = -2;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (record[i] == -1 || record[i] == -2)
                continue;
            res = min(res, record[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};