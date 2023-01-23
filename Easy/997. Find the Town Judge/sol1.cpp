class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int max = 0, judge = -1;
        vector<int> trust_cnt(n+1);
        vector<int> trusted_cnt(n+1);
        for (const auto& vec : trust) {
            trust_cnt[vec[0]]++;
            trusted_cnt[vec[1]]++;
            if (trusted_cnt[vec[1]] > max) {
                max = trusted_cnt[vec[1]];
                judge = vec[1];
            }
        }
        if (n == 1 && trust.size() == 0)
            return 1;
        if (judge != -1 && trusted_cnt[judge] == n-1 && trust_cnt[judge] == 0)
            return judge;
        return -1;
    }
};