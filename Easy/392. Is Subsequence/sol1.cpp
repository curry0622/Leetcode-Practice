class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[cnt] == t[i])
                cnt++;
        }
        return cnt == s.size();
    }
};