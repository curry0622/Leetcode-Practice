class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 1;
        int l = 0, r = 1;
        while (r < s.size()) {
            string ss = s.substr(l, r-l);
            auto idx = ss.find(s[r]);
            if (idx == string::npos)
                maxLen = max(maxLen, r-l+1);
            else
                l += idx+1;
            r++;
        }
        return s.size() == 0 ? 0 : maxLen;
    }
};