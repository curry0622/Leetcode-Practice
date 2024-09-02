class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        int n = c.size();
        int org = k;
        for (int i = 0; i < n; i++) {
            if (k < c[i])
                return i;
            k -= c[i];
        }
        int sum = org - k;
        k = k % sum;
        for (int i = 0; i < n; i++) {
            if (k < c[i])
                return i;
            k -= c[i];
        }
        return 0;
    }
    // int chalkReplacer(vector<int>& chalk, int k) {
    //     int i = 0;
    //     while (k >= 0) {
    //         if (k < chalk[i]) {
    //             break;
    //         }
    //         k -= chalk[i++];
    //         if (i >= chalk.size())
    //             i = 0;
    //     }
    //     return i;
    // }
};