class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int numWhite = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                numWhite++;
            }
        }
        int res = numWhite;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') {
                numWhite--;
            }
            if (blocks[i] == 'W') {
                numWhite++;
            }
            res = min(res, numWhite);
        }
        return res;
    }
};