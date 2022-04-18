class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        if (nLen == 0)
            return 0;
        if (hLen == nLen) {
            if (haystack.compare(needle) == 0)
                return 0;
            return -1;
        }
        for(int i = 0; i <= hLen - nLen; i++) {
            string s;
            for(int j = 0; j < nLen; j++)
                s.push_back(haystack[i + j]);
            if (s.compare(needle) == 0)
                return i;
        }
        return -1;
    }
};