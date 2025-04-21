class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> cnt(1000, 0);
        for (auto val : answers) {
            cnt[val]++;
        }
        int res = 0;
        for (int i = 0; i < 1000; i++) {
            if (cnt[i] > 0) {
                res += (i+1) * ((cnt[i]+i) / (i+1));
            }
        }
        return res;
    }
};

// 2 -> 3
// 2,2 -> 3
// 2,2,2 -> 3
// 2,2,2,2 -> 6