class Solution {
public:
    int largestCombination(vector<int>& cddts) {
        int maxLen = 0;
        for (int i = 0; i < 24; i++) {
            int len = 0;
            for (int j = 0; j < cddts.size(); j++) {
                if ((cddts[j] >> i) & 1) len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};