class Solution {
vector<int> freq;
public:
    int numTilePossibilities(string tiles) {
        freq = vector<int>(26, 0);
        int maxLen = tiles.size();
        for (char t : tiles) {
            freq[t - 'A']++;
        }
        int res = 0;
        for (int len = 1; len <= maxLen; len++) {
            res += backtracking(len);
        }
        return res;
    }

    int backtracking(int& leftLen) {
        if (leftLen <= 0) return 1;
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] <= 0) continue;
            freq[i]--;
            leftLen--;
            res += backtracking(leftLen);
            leftLen++;
            freq[i]++;
        }
        return res;
    }
};