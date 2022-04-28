class Solution {
public:
    int maxPower(string s) {
        char currChar = s[0];
        int maxLen = 1, currLen = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == currChar) {
                currLen++;
                if(currLen > maxLen) {
                    maxLen = currLen;
                }
            } else {
                currChar = s[i];
                currLen = 1;
            }
        }
        return maxLen;
    }
};