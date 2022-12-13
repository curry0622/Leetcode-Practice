class Solution {
public:
    string frequencySort(string s) {
        string ans;
        int dCnt[10] = {0}, uCnt[26] = {0}, lCnt[26] = {0};
        for(int i = 0; i < s.size(); i++) {
            if(s[i] - 'a' >= 0) {
                lCnt[s[i] - 'a']++;
            } else if(s[i] - 'A' >= 0) {
                uCnt[s[i] - 'A']++;
            } else {
                dCnt[s[i] - '0']++;
            }
        }

        for(int i = 0; i < 62; i++) {
            int maxCnt = 0, maxIdx = -1;
            for(int j = 0; j < 62; j++) {
                if(j < 10) {
                    if(maxCnt < dCnt[j]) {
                        maxCnt = dCnt[j];
                        maxIdx = j;
                    }
                } else if(j < 36) {
                    if(maxCnt < uCnt[j - 10]) {
                        maxCnt = uCnt[j - 10];
                        maxIdx = j;
                    }
                } else {
                    if(maxCnt < lCnt[j - 36]) {
                        maxCnt = lCnt[j - 36];
                        maxIdx = j;
                    }
                }
            }

            if(maxIdx >= 36) {
                for(int c = 0; c < lCnt[maxIdx - 36]; c++) {
                    ans += (char)('a' + maxIdx - 36);
                }
                lCnt[maxIdx - 36] = 0;
            } else if(maxIdx >= 10) {
                for(int c = 0; c < uCnt[maxIdx - 10]; c++) {
                    ans += (char)('A' + maxIdx - 10);
                }
                uCnt[maxIdx - 10] = 0;
            } else if(maxIdx >= 0) {
                for(int c = 0; c < dCnt[maxIdx]; c++) {
                    ans += (char)('0' + maxIdx);
                }
                dCnt[maxIdx] = 0;
            } else {
                break;
            }
        }

        return ans;
    }
};