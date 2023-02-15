class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string base = strs[0];
        int minLen = base.size();
        bool update = false;

        for (int i = 1; i < strs.size(); i++) {
            if (update)
                base = base.substr(0, minLen);
            int len = 0;
            for (int j = 0; j < min(base.size(), strs[i].size()); j++) {
                if (base[j] == strs[i][j])
                    len++;
                else
                    break;
            }
            int old = minLen;
            minLen = min(len, minLen);
            update = old == minLen;
        }

        return base.substr(0, minLen);
    }
};