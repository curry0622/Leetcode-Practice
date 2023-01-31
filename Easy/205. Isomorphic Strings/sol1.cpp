class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        unordered_map<char, char> replace;
        unordered_map<char, char> mapped;

        for (int i = 0; i < len; i++) {
            if (replace.find(t[i]) != replace.end()) {
                t[i] = replace[t[i]];
            } else {
                if (mapped.find(s[i]) != mapped.end()) {
                    // s[i] is already mapped before
                    return false;
                }
                replace[t[i]] = s[i];
                mapped[s[i]] = t[i];
                t[i] = s[i];
            }
        }

        return s == t;
    }
};