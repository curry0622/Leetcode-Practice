class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int lastLen = 0;

        for (const char& c : s) {
            if (c == ' ') {
                if (len != 0)
                    lastLen = len;
                len = 0;
            } else {
                len++;
            }
        }

        return len != 0 ? len : lastLen;
    }
};