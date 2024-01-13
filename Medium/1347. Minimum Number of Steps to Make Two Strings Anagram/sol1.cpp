class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        int len = s.size();
        int sCnt[26] = {0};
        int tCnt[26] = {0};
        for (int i = 0; i < len; i++) {
            sCnt[s[i]-'a']++;
            tCnt[t[i]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (sCnt[i] > tCnt[i])
                res += sCnt[i] - tCnt[i];
        }

        return res;
    }
};