class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (char c : s) {
            int n = c - 'a' + 1;
            while (n > 0) {
                res += n % 10;
                n /= 10;
            }
        }
        k--;
        for (; k > 0; k--) {
            int tmp = res;
            res = 0;
            while (tmp > 0) {
                res += tmp % 10;
                tmp /= 10;
            }
        }
        return res;
    }
};