class Solution {
public:
    int n = 0, m = 0;
    vector<vector<int>> memo;

    int maximumScore(vector<int>& nums, vector<int>& muls) {
        n = nums.size();
        m = muls.size();
        memo = vector<vector<int>> (m, vector<int>(m, INT_MIN));
        return dp(nums, muls, 0, 0);
    }

    int dp(const vector<int>& nums, const vector<int>& muls, int i, int k) {
        if(k >= m)
            return 0;
        if(memo[i][k] != INT_MIN)
            return memo[i][k];

        int a = 0, b = 0;
        int j = i + n - 1 - k;

        a = nums[i] * muls[k] + dp(nums, muls, i + 1, k + 1);
        b = nums[j] * muls[k] + dp(nums, muls, i, k + 1);

        return memo[i][k] = max(a, b);
    }
};